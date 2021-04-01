/*
 * myFFT.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Zach
 */

#include "myFFT.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#define SWAP(a,b) temp = (a); (a) = (b); (b) = temp

unsigned int bitReversal (unsigned int number, unsigned int numBits);

void my_DIT_FFT (float * x, int N)
{
	unsigned int i, j, k;
	unsigned int aRe, aIm, bRe, bIm;
	float tempRe, tempIm, t1, t2;
	int * stage;
	int numStages = 1, calcLog = 1;
	int n1, n2;
	int stepW, indexW;
	float c, s;
	int count = 0;

	while((calcLog <<= 1) < N) numStages++;

	/* Place input x into bit-reversed order */
	for (i = 0; i < N; i++)
	{
		j = bitReversal(i, numStages);		//find the bit reversed index

		if(j >= i)
		{
			tempRe = x[2 * i];
			tempIm = x[(2 * i) + 1];			//store the currently indexed values

			x[2 * i] = x[2 * j];
			x[(2 * i) + 1] = x[(2 * j) + 1];	//place x from bit-reversed index at current index

			x[2 * j] = tempRe;
			x[(2 * j) + 1] = tempIm;			//place stored data at bit-reversed index

//			printf("%i:\t%u\t->\t%u\t%f\n", ++count, i, j, x[2*i]);
		}
	}

	/* Perform fft */
	n1 = 0;
	n2 = 1;

	for (i = 0; i < numStages; i++)
	{
		n1 = n2;
		n2 = n2 + n2;
		stepW = W_LUT_SIZE / n2;
		indexW = 0;

		for (j = 0; j < n1; j++)
		{
			c = W[indexW];
			s = W[indexW + 1];
			indexW += stepW;

			for (k = j; k < N; k += n2)
			{
				aRe = 2 * k;
				aIm = aRe + 1;
				bRe = 2 * (k + n1);
				bIm = bRe + 1;

				tempRe = (c * x[bRe]) - (s * x[bIm]);
				tempIm = (c * x[bIm]) + (s * x[bRe]);

				x[bRe] = x[aRe] - tempRe;
				x[bIm] = x[aIm] - tempIm;

				x[aRe] = x[aRe] + tempRe;
				x[aIm] = x[aIm] + tempIm;
			}
		}
	}
}





//void my_DIF_FFT (float * x, int N)
//{
//	unsigned int i, j, k;
//	unsigned int aRe, aIm, bRe, bIm;
//	unsigned int r0, r1, rRe, rIm, separation;
//	float ReRe, ImIm, ReIm, ImRe;
//	float tempRe, tempIm;
//	int * stage;
//	int numStages = 1, calcLog = 1;
//
//	while((calcLog <<= 1) < N) numStages++;
//
//	stage = malloc(N * sizeof(int));
//	memset(stage, 0, N * sizeof(int));
//
//	separation = N / 2;
//	r0 = 1;
//
//	/* Perform fft */
//	for (i = 0; i < numStages; i++)
//	{
//		r1 = 0;
//		k = 0;
//
//		for (j = 0; j < (N / 2); j++)
//		{
//			while (stage[k] == i) ++k;			//find the first array index that hasn't been used in a butterfly
//			stage[k] = i;
//			stage[k + separation] = i;			//indicate the two indices used in this butterfly
//
//			aRe = 2 * k;
//			aIm = aRe + 1;
//			bRe = 2 * (k + separation);
//			bIm = bRe + 1;						//set top and bottom indices of butterfly in complex array
//
//			r1 &= (unsigned int)(N/2 - 1);		//determine r value for twiddle
//			rRe = (W_LUT_SIZE / N) * r1;	//determine index of twiddle value in twiddle LUT
//			rIm = rRe + 1;
//
////			ReRe = x[bRe] * W[rRe];
////			ImIm = x[bIm] * W[rIm];
////			ReIm = x[bRe] * W[rIm];
////			ImRe = x[bIm] * W[rRe];
//
////			ReRe = x[bRe] * (float)cos(2 * M_PI * r1 / N);
////			ImIm = x[bIm] * (float)sin(2 * M_PI * r1 / N);
////			ReIm = x[bRe] * (float)sin(2 * M_PI * r1 / N);
////			ImRe = x[bIm] * (float)cos(2 * M_PI * r1 / N);
//
//			tempRe = x[bRe];
//			tempIm = x[bIm];
//
//			x[bRe] = x[aRe] - x[bRe];
//			x[bIm] = x[aIm] - x[bIm];
//
//			x[aRe] = x[aRe] + tempRe;
//			x[aIm] = x[aIm] + tempIm;
//
//			tempRe = x[bRe];
//			tempIm = x[bIm];
//
//			x[bRe] = (tempRe * cos(((2 * M_PI) * r1) / N)) - (tempIm * sin(((2 * M_PI) * r1) / N));
//			x[bIm] = (tempRe * sin(((2 * M_PI) * r1) / N)) + (tempIm * cos(((2 * M_PI) * r1) / N));
//
//			r1 += r0;
//		}
//
//		r0 <<= 1;
//		separation >>= 1;
//	}
//
//	/* Place input x into bit-reversed order */
//	for (i = 1; i < (N / 2); i++)
//	{
//		tempRe = x[2 * i];
//		tempIm = x[(2 * i) + 1];			//store the currently indexed values
//
//		j = bitReversal(i, numStages);		//find the bit reversed index
//
//		x[2 * i] = x[2 * j];
//		x[(2 * i) + 1] = x[(2 * j) + 1];	//place x from bit-reversed index at current index
//
//		x[2 * j] = tempRe;
//		x[(2 * j) + 1] = tempIm;			//place stored data at bit-reversed index
//	}
//}





unsigned int bitReversal (unsigned int number, unsigned int numBits)
{
	unsigned int reversed = 0;

	int i;
	for (i = 0; i < numBits; i++)
	{
		if (number & (1 << i))
		{
			reversed |= 1 << ((numBits - 1) - i);
		}
	}

	return reversed;
}
