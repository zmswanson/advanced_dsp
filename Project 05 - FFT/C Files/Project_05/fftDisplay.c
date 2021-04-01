/*
 * oscDisplay.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Zach
 */

#include "stdint.h"
#include "ezdsp5535_lcd.h"
#include "ezdsp5535_gpio.h"
#include "ezdsp5535_i2c.h"

void initLCDVertAddr( void )
{
	Uint16 cmd[4];

	cmd[0] = 0x00 & 0x00FF;
	cmd[1] = 0x20;
	cmd[2] = 0x01;
    EZDSP5535_waitusec( 250 );
	EZDSP5535_I2C_write(0x3C, cmd, 3);

	cmd[0] = 0x00 & 0x00FF;
	cmd[1] = 0x21;
	cmd[2] = 0x00;
	cmd[3] = 0x5f;
    EZDSP5535_waitusec( 250 );
	EZDSP5535_I2C_write(0x3C, cmd, 4);

	cmd[0] = 0x00 & 0x00FF;
	cmd[1] = 0x22;
	cmd[2] = 0x00;
	cmd[3] = 0x01;
    EZDSP5535_waitusec( 250 );
	EZDSP5535_I2C_write(0x3C, cmd, 4);
}

void pixLoc(int16_t sample, Uint16 * bot, Uint16 * top, int maxVal)
{
	int i;
	Uint32 temp = 0x01;

	if(maxVal < 100)
	{
		maxVal = 32767;
	}

	for( i = 1; i < 16; i++)
	{
		if(sample > (i * (maxVal / 16)))
		{
			temp |= temp << 1;
		}

		else
		{
			i = 16;
		}
	}

	*bot = (Uint16)(temp);
	*top = (Uint16)(temp >> 8);
}

void fftDisplay(int16_t * samples, int numSamps, int16_t maxVal)
{
//	Uns olstate = HWI_disable();
//	TSK_disable();

	int i, j;
	Uint16 bot, top, cmd[193];

	cmd[0] = 0x40 & 0x00FF;

	for(i = 0, j = 1; i < 96; i++, j+=2)
	{
		pixLoc(samples[i], &bot, &top, maxVal);

		cmd[j] = bot;
		cmd[(j + 1)] = top;
	}

	EZDSP5535_waitusec( 10 );
	EZDSP5535_I2C_write(0x3C, &cmd[0], 193);

//	HWI_restore(olstate);
//	TSK_enable();
}
