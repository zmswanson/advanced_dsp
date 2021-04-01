/*
 * audioProcessing.h
 *
 *  Created on: Mar 29, 2018
 *      Author: Zach
 */

#include "stdint.h"
#include "string.h"
#include "dsplib.h"
#include "filters.h"

/**********************************************************************************
 ************************************  DEFINES  ***********************************
 **********************************************************************************/

#define NX		48				// number of samples filtered per myfir call
#define N		256				// N-point FFT
#define N2		512				// N doubled
#define NBY2	128				// N halved

/************************************************************************************
 ************************************  FUNCTIONS  ***********************************
 ************************************************************************************/

extern CSL_I2sHandle   hI2s;
extern void myfir(const int16_t* input, const int16_t* filterCoeffs, int16_t* output, int16_t* delayLine, uint16_t  nx, uint16_t  nh);
extern int16_t myNCO(uint16_t f_tone);
extern void clearPA(void);
extern void initLCDVertAddr( void );
extern void fftDisplay(int16_t * samples, int numSamps, int16_t maxVal);

/*********************************************************************************
 *******************************  ARRAYS + POINTERS  *****************************
 *********************************************************************************/

int16_t rxPingPong[96];						// array of received audio (2 blocks of 48)
int16_t txPingPong[96];						// array of audio to transmit (2 blocks of 48)

int16_t delayLineLPF[NX + LPF_NH - 1];		// delay line for low-pass filter
int16_t delayLineHPF[NX + HPF_NH - 1];		// delay line for high-pass filter

int16_t * filterPtr;						// pointer to select low- or high- pass filter
int16_t * delayLinePtr;						// pointer to select delay line for LPF or HPF

#pragma DATA_ALIGN(fftData,2);
DATA fftData[N];
#pragma DATA_ALIGN(data1,2);
DATA data1[N];
int16_t fftMag[NBY2+1];

/*********************************************************************************
 ***********************************  VARIABLES  *********************************
 *********************************************************************************/

int16_t rxIndex;				// 0: samples 1-48; 1: samples 49-96
int16_t txIndex;				// 0: samples 1-48; 1: samples 49-96
int16_t ppIndex;				// 0: samples 1-48; 1: samples 49-96
int16_t fftIndex;				// 0: samples 1-N; 1: samples N+1-2N
int16_t dataIndex;				// ??

uint16_t sw1State  = 0;       	// SW1 state
uint16_t sw2State  = 0;       	// SW2 state
uint16_t filtState;				// 1: low-pass filter; 0: high-pass filter

uint16_t myNH;					// length of selected filter

int displayFreeze = 0;			// 0: no update; 1: update graph
