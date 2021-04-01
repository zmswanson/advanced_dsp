/*
 * oscDisplay.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Zach
 */

#include "stdint.h"
#include "ezdsp5535_lcd.h"
#include "ezdsp5535_gpio.h"

void pixLoc(int16_t sample, int * topBot, Uint16 * loc8)
{
	int i;

	if(sample < 0 )
	{
		*loc8 = 0x01;
		* topBot = 1;
		sample = sample * (-1);

		for( i = 1; i < 8; i++)
		{
			if(sample > (i * (32768 / 8)))
			{
				* loc8 = (* loc8) << 1;
			}
		}
	} else if(sample > 0) {
		*loc8 = 0x80;
		* topBot = 0;

		for( i = 1; i < 8; i++)
		{
			if(sample > (i * (32768 / 8)))
			{
				* loc8 = (* loc8) >> 1;
			}
		}
	} else {
		*loc8 = 0x00;
		*topBot = 0;
	}
}

void oscDisplay(int16_t * samples, int numSamps)
{
//	Uns olstate = HWI_disable();
//	TSK_disable();

//	EZDSP5535_GPIO_setOutput( 14, 0 );

	int i, j;
	int topBot;
	Uint16 loc8;

	/* Fill page 0 */
	EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
	EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
	EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5

	for(i=0;i<128;i++)
	{
		EZDSP5535_OSD9616_send(0x40,0x00);
	}

	/* Fill page 1*/
	EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
	EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
	EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5

	for(i=0;i<128;i++)
	{
		EZDSP5535_OSD9616_send(0x40,0x00);
	}

	EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
	EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address

	for(j = 0; j < 96; j++)
	{
		pixLoc(samples[j], &topBot, &loc8);
		EZDSP5535_OSD9616_send(0x00,0xb0+topBot); // Set page for page 0 to page 5
		EZDSP5535_OSD9616_send(0x40,loc8);
	}

//	EZDSP5535_GPIO_setOutput( 14, 1 );

//	HWI_restore(olstate);
//	TSK_enable();
}
