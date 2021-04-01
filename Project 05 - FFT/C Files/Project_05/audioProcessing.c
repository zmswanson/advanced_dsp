/*
 *  Copyright 2010 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 */
/***************************************************************************/
/*                                                                         */
/*     H E L L O . C                                                       */
/*                                                                         */
/*     Basic LOG event operation from main.                                */
/*                                                                         */
/***************************************************************************/

#include <std.h>

#include <log.h>

#include "stdint.h"
#include "string.h"
#include "math.h"
#include "hellocfg.h"
#include "ezdsp5535.h"
#include "ezdsp5535_gpio.h"
#include "ezdsp5535_i2s.h"
#include "ezdsp5535_led.h"
#include "ezdsp5535_sar.h"
#include "csl_i2s.h"
#include "csl_gpio.h"
#include "aic3204.h"
#include "audioProcessing.h"
#include "dsplib.h"

/*
 * audioProcessingInit
 *
 * @brief: 	Initialize arrays used for filtering and transmitting
 * 			and initialize array indices to 0.
 */
void audioProcessingInit(void)
{
	initLCDVertAddr();

	/* Initialize arrays as empty*/
	memset(txPingPong, 0, sizeof(rxPingPong) * sizeof(int16_t));
	memset(txPingPong, 0, sizeof(txPingPong) * sizeof(int16_t));
	memset(delayLineLPF, 0, sizeof(delayLineLPF) * sizeof(int16_t));
	memset(delayLineHPF, 0, sizeof(delayLineHPF) * sizeof(int16_t));
	memset(fftData, 0, sizeof(fftData) * sizeof(DATA));

	/* Initially select low-pass filter */
	filterPtr = &myLPF[0];
	delayLinePtr = &delayLineLPF[0];
	myNH = LPF_NH;
	filtState = 1;

	/* Initialize rx and tx indices to 0 */
	rxIndex = 0;
	txIndex = 0;
	ppIndex = 0;
	dataIndex = 0;
}

/**********************************************************************
 *******************              HWIs              *******************
 **********************************************************************/

/*
 * HWI_I2S_Rx
 *
 * @brief: 	Function handle for HWI 15. Stores received samples into a
 * 			double buffer and post SWIs to perform filtering.
 */
void HWI_I2S_Rx(void)
{
	volatile int16_t temp;
	temp = hI2s->hwRegs->I2SRXRT1;
	rxPingPong[rxIndex++] = hI2s->hwRegs->I2SRXLT1;

	if (rxIndex == 48)		//Have 48 samples been collected
	{
		MBX_post(&MBXAudio, &rxPingPong[0], 0);
	}

	if (rxIndex == 96)
	{
		MBX_post(&MBXAudio, &rxPingPong[48], 0);
		rxIndex = 0;
	}
}

/************************************************************************
 * HWI_I2S_Tx															*
 *																		*
 * @brief: 	Function handle for HWI 14. Transmits filtered samples		*
 * 			from a double buffer.										*
 ************************************************************************/
void HWI_I2S_Tx(void)
{
	/* Transmit filtered samples */
	hI2s->hwRegs->I2STXLT1 = txPingPong[txIndex];
	hI2s->hwRegs->I2STXRT1 = txPingPong[txIndex++];

	if (txIndex == 96)		//Have 96 samples been transmitted?
	{
		txIndex = 0;
	}
}

/**********************************************************************
 *******************              TSKs              *******************
 **********************************************************************/

void TSKPingPongFunc(void)
{
	int i;
	int16_t ping[48], pong[48];

	while(1)
 	{
		if(ppIndex == 0)
		{
	 		MBX_pend(&MBXAudio, &ping, SYS_FOREVER);

			myfir(&ping[0], filterPtr, &txPingPong[0], delayLinePtr, NX, myNH);
	 		ppIndex = 1;

	 		for(i = 0; i < 48; i++)
	 		{
	 			fftData[dataIndex++] = (DATA)txPingPong[i];

	 			if(dataIndex == N)
	 			{
	 				MBX_post(&MBXfft, &fftData[0], 0);
	 				dataIndex = 0;
	 			}
	 		}
		}

		else if (ppIndex == 1)
		{
	 		MBX_pend(&MBXAudio, &pong, SYS_FOREVER);

			myfir(&pong[0], filterPtr, &txPingPong[48], delayLinePtr, NX, myNH);
	 		for(i = 48; i < 96; i++)
	 		ppIndex = 0;

	 		for(i = 48; i < 96; i++)
	 		{
	 			fftData[dataIndex++] = (DATA)txPingPong[i];

	 			if(dataIndex == N)
	 			{
	 				MBX_post(&MBXfft, &fftData[0], 0);
	 				dataIndex = 0;
	 			}
	 		}
		}
 	}
}

void TSK_FFT_Func(void)
{
	int i, j;
	int16_t max;

	while(1)
	{
		MBX_pend(&MBXfft, &data1, SYS_FOREVER);
		max = 0;
		rfft(data1, N, SCALE);

		IDL_run();

		fftMag[0] = (int16_t)(sqrt( pow((double)(data1[0]), 2) ) );
		fftMag[NBY2] = (int16_t)(sqrt( pow((double)(data1[1]), 2) ) );

		for(i = 1, j = 2; i < NBY2; i++, j += 2)
		{
			fftMag[i] = (int16_t)(sqrt( pow((double)(data1[j]), 2) + pow((double)(data1[(j + 1)]), 2) ) );

			if(fftMag[i] > max)
			{
				max = fftMag[i];
			}
		}

		IDL_run();

		if(!displayFreeze)
		{
			fftDisplay(fftMag, NBY2, max);
		}
	}
}

/**********************************************************************
 *******************              IDLs              *******************
 **********************************************************************/

void monitorSW1(void)
{
	/* Check SW1 */
	if(EZDSP5535_SAR_getKey( ) == SW1) 		// Is SW1 pressed?
	{
		if(sw1State)             			// Was previous state not pressed?
		{
			if(displayFreeze)
			{
				displayFreeze = 0;
			} else {
				displayFreeze = 1;
			}

			sw1State = 0;     				// Set state to 0 to allow only single press
		}
	} else                      			// SW1 not pressed
	{
		sw1State = 1;         				// Set state to 1 to allow timer change
	}
}

void monitorSW2(void)
{
	/* Check SW2 */
	if(EZDSP5535_SAR_getKey( ) == SW2) 		// Is SW2 pressed?
	{
		if(sw2State)          				// Was previous state not pressed?
		{
			Uns olstate = HWI_disable();
			TSK_disable();

			if(filtState)					//Was previous state High-pass?
			{
				/* Clear Low-pass delayLine */
				memset(delayLineLPF, 0, sizeof(delayLineHPF)*sizeof(int16_t));

				/* Point filter pointer to myLPF */
				filterPtr = &myLPF[0];

				/* Point delay line pointer to delayLineLPF */
				delayLinePtr = &delayLineLPF[0];

				/* Set myNH to number of low-pass coefficients */
				myNH = LPF_NH;

				/* Set filtState to low-pass */
				filtState = 0;
			} else				//Was previous state low-pass
			{
				/* Clear high-pass delay line */
				memset(delayLineHPF, 0, sizeof(delayLineHPF)*sizeof(int16_t));

				/* Point filter pointer to myHPF */
				filterPtr = &myHPF[0];

				/* Point delayline pointer to delayLineHPF */
				delayLinePtr = &delayLineHPF[0];

				/* Set my NH to number of high-pass coefficients */
				myNH = HPF_NH;

				/* Set filtState to high-pass */
				filtState = 1;
			}

			HWI_restore(olstate);
			TSK_enable();
			sw2State = 0;     				// Set state to 0 to allow only single press
		}
	} else                      			// SW2 not pressed
	{
		sw2State = 1;         				// Set state to 1 to allow tone change
	}
}
