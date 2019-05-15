#include <LPC21xx.H>
#include "led.h"
#include "timer_interrups.h"
#include "keyboard.h"
#include "servo.h"


void Automat()
{
	enum LedState{STAY,MOVE_LEFT, MOVE_RIGHT, CALLIB};
	static enum LedState eLedState = CALLIB;

	switch(eLedState)
		{
			case CALLIB:
				if(eReadDetector() == INACTIVE)
				{
					LedStepRight();
				}
				else
				{
					LedStepLeft();
				}
				break;
				
			case MOVE_LEFT:
				if(eKeyboardRead() == BUTTON_1)
				{
					eLedState = STAY;
				}
				else
				{
					LedStepLeft();
				}
				break;
				
			case MOVE_RIGHT:
				if(eKeyboardRead() == BUTTON_1)
				{
					eLedState = STAY;
				}
				else
				{
					LedStepRight();
				}
				break;
			
			case STAY:
				if(eKeyboardRead() == BUTTON_0)
				{
					eLedState = MOVE_LEFT;
				}
				else if(eKeyboardRead() == BUTTON_2)
				{
					eLedState = MOVE_RIGHT;
				}
				break;
		}
}

int main ()
{
	unsigned int iMainLoopCtr;
	
	DetectorInit();
	Timer0Interrupts_Init(200000, &Automat);

	while(1)
	{
	 	iMainLoopCtr++;
	}
}
