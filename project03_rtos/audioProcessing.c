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
#include "ezdsp5535_led.h"
#include "ezdsp5535_sar.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"
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
extern int16_t signalAttenuate (int16_t signal, uint16_t attenuation);

int16_t rxPingPong[96];
int16_t txPingPong[96];

int16_t delayLineLPF[NX + LPF_NH - 1];
int16_t delayLineHPF[NX + HPF_NH - 1];

int16_t rxIndex;
int16_t txIndex;

uint16_t sw1State  = 0;       	// SW1 state
uint16_t sw2State  = 0;       	// SW2 state
uint16_t filtState = 0;			// filter state

int16_t * filterPtr;
int16_t * delayLinePtr;
uint16_t myNH;

void audioProcessingInit(void)
{
	memset(txPingPong, 0, sizeof(txPingPong));
	memset(delayLineLPF, 0, sizeof(delayLineLPF));
	memset(delayLineHPF, 0, sizeof(delayLineHPF));
	filterPtr = &myLPF[0];
	delayLinePtr = &delayLineLPF[0];
	myNH = LPF_NH;
	rxIndex = 0;
	txIndex = 0;
}

/**********************************************************************
 *******************              HWIs              *******************
 **********************************************************************/

void HWI_I2S_Rx(void)
{
	EZDSP5535_LED_setall(BL_ONLY);

	volatile int16_t temp;

	temp = hI2s->hwRegs->I2SRXRT1;
	rxPingPong[rxIndex++] = hI2s->hwRegs->I2SRXLT1;
	if (rxIndex == 48)
	{
		// ping is full
		SWI_post(&SWIPing);
	}
	if (rxIndex == 96)
	{
		// pong is full
		SWI_post(&SWIPong);
		rxIndex = 0;
	}
}

void HWI_I2S_Tx(void)
{
	hI2s->hwRegs->I2STXLT1 = txPingPong[txIndex];
	hI2s->hwRegs->I2STXRT1 = txPingPong[txIndex++];
	if (txIndex == 96)
	{
	 txIndex = 0;
	}

	 EZDSP5535_LED_setall(BL_ONLY);
}

/**********************************************************************
 *******************              SWIs              *******************
 **********************************************************************/

void SWIPingFunc(void)
{
	EZDSP5535_LED_setall(YL_ONLY);

	myfir(&rxPingPong[0], filterPtr, &txPingPong[0], delayLinePtr, NX, myNH);
}

void SWIPongFunc(void)
{
	EZDSP5535_LED_setall(YL_ONLY);

	myfir(&rxPingPong[48], filterPtr, &txPingPong[48], delayLinePtr, NX, myNH);
}

/**********************************************************************
 *******************              IDLs              *******************
 **********************************************************************/

void monitorSW1(void)
{
	EZDSP5535_LED_setall(RD_ONLY);
	/* Check SW1 */
	if(EZDSP5535_SAR_getKey( ) == SW1) // Is SW1 pressed?
	{
		if(sw1State)              // Was previous state not pressed?
		{
			int16_t msec, sample;

			SWI_disable( );
			Uns oldState1 = HWI_disable( );
			for ( msec = 0 ; msec < 1000 ; msec++ )
			{
				for ( sample = 0 ; sample < 48 ; sample++ )
				{
					int16_t temp = (myNCO( 1000 ) >> 5);

	                /* Write 16-bit left channel Data */
	                EZDSP5535_I2S_writeLeft( temp );

	                /* Write 16-bit right channel Data */
	                EZDSP5535_I2S_writeRight( temp );
				}
			}
			clearPA( );
			memset(delayLineLPF, 0, sizeof(delayLineLPF));
			memset(delayLineHPF, 0, sizeof(delayLineHPF));
			rxIndex = 0;
			txIndex = 0;

			HWI_restore( oldState1 );
			SWI_enable( );

			sw1State = 0;     // Set state to 0 to allow only single press
		}
	} else                      // SW1 not pressed
	{
		sw1State = 1;         // Set state to 1 to allow timer change
	}
}

void monitorSW2(void)
{
	/* Check SW2 */
	if(EZDSP5535_SAR_getKey( ) == SW2) // Is SW2 pressed?
	{

		if(sw2State)          // Was previous state not pressed?
		{
			if(filtState)
			{
				memset(delayLineLPF, 0, sizeof(delayLineLPF));

				filterPtr = &myLPF[0];
				delayLinePtr = &delayLineLPF[0];
				myNH = LPF_NH;

				filtState = 0;
			} else
			{
				memset(delayLineHPF, 0, sizeof(delayLineHPF));

				filterPtr = &myHPF[0];
				delayLinePtr = &delayLineHPF[0];
				myNH = HPF_NH;

				filtState = 1;
			}

			sw2State = 0;     // Set state to 0 to allow only single press
		}
	} else                      // SW2 not pressed
	{

		sw2State = 1;         // Set state to 1 to allow tone change
	}
}

/**********************************************************************
 *******************              TSKs              *******************
 **********************************************************************/
