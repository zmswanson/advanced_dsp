/*
 * myFFT.c
 *
 *  Created on: Apr 10, 2018
 *      Author: Zach
 */

#include "myFFT.h"

uint16_t bitReversal (uint16_t number);

void myFFT (int16_t * data, int16_t N)
{
	uint16_t i, j, k, top, bott, r0, r1, r2, separation;
	int16_t tempRe, tempIm;
	int16_t * stage;

	stage = malloc(N * sizeof(int16_t));

	/* Place input data into bit-reversed order */
	for (i = 1; i < (N / 2); i++)
	{
		tempRe = data[2 * i];
		tempIm = data[(2 * i) + 1];		//store the currently indexed values

		j = bitReversal(i);		//find the bit reversed index

		data[2 * i] = data[2 * j];
		data[(2 * i) + 1] = data[(2 * j) + 1];	//place data from bit-reversed index at current index

		data[2 * j] = tempRe;
		data[(2 * j) + 1] = tempIm;		//place stored data at bit-reversed index
	}

	for (i = 1; i < (log2(N) + 1); i++)
	{
		r0 = N / pow(2, i);
		r1 = 0;
		separation = pow(2, (i - 1));
		k = 0;

		for (j = 0; j < (N / 2); j++)
		{
			while (stage[k] == i) ++k;	//find the first array index that hasn't been used in a butterfly
			stage[k] = i;
			stage[k + separation] = i;	//indicate the two indices used in this butterfly

			top = 2 * k;
			bott = 2 * (k + separation);	//set top and bottom indices of butterfly in complex array

			r1 += r0;
			r1 &= (uint16_t)(N/2 - 1);	//determine r value for twiddle
			r2 = 2 * (TWIDDLE_LUT_SIZE / N) * r1;	//determine index of twiddle value in twiddle LUT

			tempRe = data[top] - (data[bott] * twiddleLUT[r2]) - (data[bott + 1] * twiddleLUT[r2 + 1]);
			tempIm = data[top + 1] + (data[bott] * twiddleLUT[r2 + 1]) - (data[bott + 1] * twiddleLUT[r2]);

			data[top] = data[top] + (data[bott] * twiddleLUT[r2]) + (data[bott + 1] * twiddleLUT[r2 + 1]);
			data[top + 1] = data[top + 1] - (data[bott] * twiddleLUT[r2 + 1]) + (data[bott + 1] * twiddleLUT[r2]);

			data[bott] = tempRe;
			data[bott + 1] = tempIm;
		}
	}
}

uint16_t bitReversal (uint16_t number)
{
	uint16_t numBits = sizeof(number) * 8;
	uint16_t reversed = 0;

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
