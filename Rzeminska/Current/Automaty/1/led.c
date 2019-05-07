#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)


enum LedDirection {LEFT, RIGHT};


void LedInit()
{
	IO1DIR = IO1DIR | ( LED0_bm | LED1_bm | LED2_bm | LED3_bm );
	
	IO1CLR = LED1_bm | LED2_bm | LED3_bm;
	
	IO1SET =  LED0_bm;
}

void LedOn(unsigned char ucLedIndeks)
{
	switch(ucLedIndeks)
	{
		case 0:
			IO1CLR = LED1_bm | LED2_bm | LED3_bm;
			IO1SET = LED0_bm;
			break;
		
		case 1:
			IO1CLR = LED0_bm | LED2_bm | LED3_bm;
			IO1SET = LED1_bm;
			break;
		
		case 2:
			IO1CLR = LED0_bm | LED1_bm | LED3_bm;
			IO1SET = LED2_bm;
			break;
		
		case 3:
			IO1CLR = LED0_bm | LED1_bm | LED2_bm;
			IO1SET = LED3_bm;
			break;
		
		default:
			break;
	}
}

void LedStep(enum LedDirection Direction)
{
	static unsigned int uiLedCounter = 0;
	
	if(Direction == LEFT)
	{
		uiLedCounter++;
	}
	
	else
	{
		uiLedCounter--;
	}
	
	LedOn(uiLedCounter%4);
}


void LedStepLeft(void)
{
	LedStep(LEFT);
}

void LedStepRight(void)
{
	LedStep(RIGHT);
}


