/*
 * myFFT.h
 *
 *  Created on: Apr 10, 2018
 *      Author: Zach
 */

#ifndef MYFFT_H_
#define MYFFT_H_

#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

#define W_LUT_SIZE			2048
#define REAL				0
#define COMPLEX				1
#define NOSCALE				0
#define SCALE				1
#define FORWARD				1
#define BACKWARD			-1

extern int myFFT (int * x, int N, int scale, int direction, int real);

extern const int realW[];

extern const int imagW_bkd[];

extern const int imagW_fwd[];

#endif /* MYFFT_H_ */
