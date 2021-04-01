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
#include "hellocfg.h"
#include "ezdsp5535.h"
#include "ezdsp5535_gpio.h"
#include "ezdsp5535_i2s.h"
#include "ezdsp5535_led.h"
#include "ezdsp5535_sar.h"
#include "csl_i2s.h"
#include "csl_gpio.h"
#include "aic3204.h"
#include "filters.h"

#define NX			48
#define BL_ONLY		0x0E
#define YL_ONLY		0x0D
#define RD_ONLY		0x0B
#define GR_ONLY		0x07
#define MIN(a,b) ( ((a) <  (b)) ? (a) : (b) )

extern CSL_I2sHandle   hI2s;
extern void myfir(const int16_t* input, const int16_t* filterCoeffs,
		int16_t* output, int16_t* delayLine, uint16_t  nx, uint16_t  nh);
extern int16_t myNCO(uint16_t f_tone);
extern void clearPA(void);

int16_t rxPingPong[96];
int16_t txPingPong[96];
int16_t preDecSamps[576], preAA[576], postAA[576];
int16_t delayLineAA[576 + 121 - 1];
int16_t disp96[96];
int16_t finalDisp[96];

int16_t delayLineLPF[NX + LPF_NH - 1];
int16_t delayLineHPF[NX + HPF_NH - 1];

int16_t rxIndex;
int16_t txIndex;
int16_t ppIndex;
int16_t preDecIndex;
int16_t dispIndex;
int16_t deciIndex;

uint16_t sw1State  = 0;       	// SW1 state
uint16_t sw2State  = 0;       	// SW2 state
uint16_t filtState = 0;			// filter state

int16_t * filterPtr;
int16_t * delayLinePtr;
uint16_t myNH;


Uint16 idl = 0, swi = 0;

int displayGraph = 0;

extern void oscDisplay(int16_t * samples, int numSamps);

/*
 * audioProcessingInit
 *
 * @brief: 	Initialize arrays used for filtering and transmitting
 * 			and initialize array indices to 0.
 */
void audioProcessingInit(void)
{
	/* Initialize arrays as empty*/
	memset(txPingPong, 0, sizeof(txPingPong));
	memset(delayLineLPF, 0, sizeof(delayLineLPF));
	memset(delayLineHPF, 0, sizeof(delayLineHPF));

	/* Initially select low-pass filter */
	filterPtr = &myLPF[0];
	delayLinePtr = &delayLineLPF[0];
	myNH = LPF_NH;

	/* Initialize rx and tx indices to 0 */
	rxIndex = 0;
	txIndex = 0;
	ppIndex = 0;
	preDecIndex = 0;
	deciIndex = 0;
	dispIndex = 0;
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
//	EZDSP5535_GPIO_setOutput( 14, 1 );

	/* Read right sample and disregard. Read left sample and store
	 * in rxPingPong.
	 * Ping -> first 48 samples in array (0 - 47)
	 * Pong -> second 48 samples in array (48 - 97)
	 */
	volatile int16_t temp;
	temp = hI2s->hwRegs->I2SRXRT1;
	rxPingPong[rxIndex++] = hI2s->hwRegs->I2SRXLT1;
	preDecSamps[preDecIndex++] = temp;

	if (rxIndex == 48)		//Have 48 samples been collected
	{
		/* Ping is full -> Post SWIPing to run SWI that will
		 * filter the ping samples.
		 */
		MBX_post(&MBXAudio, &rxPingPong[0], 0);
	}

	if (rxIndex == 96)
	{
		/* Pong is full -> Post SWIPong to run SWI that will
		 * filter the pong samples. Clear rxIndex so rxPingPong
		 * will begin filling ping again.
		 */
		MBX_post(&MBXAudio, &rxPingPong[48], 0);
		rxIndex = 0;
	}

	if(preDecIndex == 576)
	{
		MBX_post(&MBXDecimate, &preDecSamps[0], 0);
		preDecIndex = 0;
	}

	EZDSP5535_GPIO_setOutput( 14, 0 );
}

/*
 * HWI_I2S_Tx
 *
 * @brief: 	Function handle for HWI 14. Transmits filtered samples
 * 			from a double buffer.
 */
void HWI_I2S_Tx(void)
{
	/* Transmit filtered samples */
	hI2s->hwRegs->I2STXLT1 = txPingPong[txIndex];
	hI2s->hwRegs->I2STXRT1 = txPingPong[txIndex++];

	if (txIndex == 96)		//Have 96 samples been transmitted?
	{
		/* Set index to beginning of tx array */
		txIndex = 0;
	}
}

/**********************************************************************
 *******************              TSKs              *******************
 **********************************************************************/

void TSKPingPongFunc(void)
{
	int16_t ping[48], pong[48];

    /* Filter a frame of 48 received samples and store output in tx buffer
     *  using myfir. Variables filterPtr and delayLinePtr point to the desired
     *  filter (LPF or HPF) and it's corresponding delayline (selected in second IDL
     *  thread).
     */
	while(1)
 	{
		if(ppIndex == 0)
		{
	 		MBX_pend(&MBXAudio, &ping, SYS_FOREVER);
//			EZDSP5535_GPIO_setOutput( 15, 1 );
	 		myfir(&ping[0], filterPtr, &txPingPong[0], delayLinePtr, NX, myNH);
	 		ppIndex = 1;
		} else if (ppIndex == 1)
		{
	 		MBX_pend(&MBXAudio, &pong, SYS_FOREVER);
//			EZDSP5535_GPIO_setOutput( 15, 1 );
	 		myfir(&pong[0], filterPtr, &txPingPong[48], delayLinePtr, NX, myNH);
	 		ppIndex = 0;
		}

//		EZDSP5535_GPIO_setOutput( 15, 0 );
 	}
}

void TSKDecimateFunc(void)
{
	int i;

	while(1)
	{
		MBX_pend(&MBXDecimate, &preAA, SYS_FOREVER);
//		EZDSP5535_GPIO_setOutput( 17, 1 );
		myfir(&preAA[0], sharpAA, &postAA[0], delayLineAA, 576, 121);
		IDL_run();

		disp96[0] = postAA[0];

		for(i = 6; i < 576; i++)
		{
			if((i % 6) == 0)
			{
				disp96[i/6] = postAA[i];
			}
		}

		IDL_run();
		if(displayGraph == 1)
		{
			oscDisplay(disp96, 96);
			displayGraph = 0;
		}

//		EZDSP5535_GPIO_setOutput( 17, 0 );
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
			displayGraph = 1;				//Tell TSK to display graph

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
			if(filtState)					//Was previous state High-pass?
			{
				/* Clear Low-pass delayLine */
				memset(delayLineLPF, 0, sizeof(delayLineLPF));

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
				memset(delayLineHPF, 0, sizeof(delayLineHPF));

				/* Point filter pointer to myHPF */
				filterPtr = &myHPF[0];

				/* Point delayline pointer to delayLineHPF */
				delayLinePtr = &delayLineHPF[0];

				/* Set my NH to number of high-pass coefficients */
				myNH = HPF_NH;

				/* Set filtState to high-pass */
				filtState = 1;
			}
			sw2State = 0;     				// Set state to 0 to allow only single press
		}
	} else                      			// SW2 not pressed
	{
		sw2State = 1;         				// Set state to 1 to allow tone change
	}
}

/**********************************************************************
 *******************              TSKs              *******************
 **********************************************************************/
