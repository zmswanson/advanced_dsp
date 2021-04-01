///*
// * myFFT.c
// *
// *  Created on: Apr 10, 2018
// *      Author: Zach
// */
//
//#include "myFFT.h"
//#include "stdio.h"
//
//unsigned int bitReversal (unsigned int number, unsigned int numBits);
//
//void myFFT (int * x, int N)
//{
//	unsigned int i, j, k;
//	unsigned int aRe, aIm, bRe, bIm;
//	unsigned int r0, r1, rRe, rIm, separation;
//	int ReRe, ImIm, ReIm, ImRe;
//	int tempRe, tempIm;
//	int * stage;
//	int numStages = 1, calcLog = 1;
//
//	while((calcLog *= 2) < N) numStages++;
//
//	stage = malloc(N * sizeof(int));
//	separation = 1;
//	r0 = N / 2;
//
//	/* Place input x into bit-reversed order */
//	for (i = 1; i < (N / 2); i++)
//	{
//		tempRe = x[2 * i];
//		tempIm = x[(2 * i) + 1];		//store the currently indexed values
//
//		j = bitReversal(i, numStages);	//find the bit reversed index
//
//		if(j > i)
//		{
//			x[2 * i] = x[2 * j];
//			x[(2 * i) + 1] = x[(2 * j) + 1];	//place x from bit-reversed index at current index
//
//			x[2 * j] = tempRe;
//			x[(2 * j) + 1] = tempIm;		//place stored data at bit-reversed index
//		}
//	}
//
//	/* Perform fft */
//	for (i = 1; i < (numStages + 1); i++)
//	{
//		r1 = 0;
//		k = 0;
//
//		for (j = 0; j < (N / 2); j++)
//		{
//			while (stage[k] == i) ++k;	//find the first array index that hasn't been used in a butterfly
//			stage[k] = i;
//			stage[k + separation] = i;	//indicate the two indices used in this butterfly
//
//			aRe = 2 * k;
//			aIm = aRe + 1;
//			bRe = 2 * (k + separation);
//			bIm = bRe + 1;	//set top and bottom indices of butterfly in complex array
//
//			r1 &= (unsigned int)(N/2 - 1);	//determine r value for twiddle
//			rRe = (TWIDDLE_LUT_SIZE / N) * r1;	//determine index of twiddle value in twiddle LUT
//			rIm = rRe + 1;
//			r1 += r0;
//
////			ReRe = (int)(((long)(x[bRe]) * (long)(W[rRe])) >> 16);
////			ImIm = (int)(((long)(x[bIm]) * (long)(W[rIm])) >> 16);
////			ReIm = (int)(((long)(x[bRe]) * (long)(W[rIm])) >> 16);
////			ImRe = (int)(((long)(x[bIm]) * (long)(W[rRe])) >> 16);
//
//			ReRe = (int)((_lsmpy(x[bRe], W[rRe])) >> 17);
//			ImIm = (int)((_lsmpy(x[bIm], W[rIm])) >> 17);
//			ReIm = (int)((_lsmpy(x[bRe], W[rIm])) >> 17);
//			ImRe = (int)((_lsmpy(x[bIm], W[rRe])) >> 17);
//
//			tempRe = _ssub(ReRe, ImIm);
//			tempIm = _sadd(ReIm, ImRe);
//
////			tempRe = _sadd(ReRe, ImIm);
////			tempIm = _ssub(ImRe, ReIm);
//
//			x[bRe] = _ssub(x[aRe], tempRe) >> 1;
//			x[bIm] = _ssub(x[aIm], tempIm) >> 1;
//
//			x[aRe] = _sadd(x[aRe], tempRe) >> 1;
//			x[aIm] = _sadd(x[aIm], tempIm) >> 1;
//
////			printf("x[%u] = %i + j%i\tx[%u] = %i + j%i\t\n", (aRe/2), x[aRe], x[aIm], (bRe/2), x[bRe], x[bIm]);
//		}
//
//		r0 /= 2;
//		separation *= 2;
//
////		printf("\n*** END OF STAGE %u ***\n", i);
//	}
//}
//
//unsigned int bitReversal (unsigned int number, unsigned int numBits)
//{
//	unsigned int reversed = 0;
//
//	int i;
//	for (i = 0; i < numBits; i++)
//	{
//		if (number & (1 << i))
//		{
//			reversed |= 1 << ((numBits - 1) - i);
//		}
//	}
//
//	return reversed;
//}
