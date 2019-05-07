#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


enum LedState{STAY,MOVE_LEFT, MOVE_RIGHT};
enum LedState eLedState = STAY;


int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		
		switch(eLedState)
		{
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
		Delay(100);	
	}	
}

