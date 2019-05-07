#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


enum LedState{STAY, MOVE_RIGHT};
enum LedState eLedState = MOVE_RIGHT;


int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		
		switch(eLedState)
		{
			case MOVE_RIGHT:
				if(eKeyboardRead() == BUTTON_0)
				{
					eLedState = STAY;
				}
				else
				{
					LedStepRight();
				}
				break;
			
			case STAY:
				if(eKeyboardRead() == BUTTON_1)
				{
					eLedState = MOVE_RIGHT;
				}
				break;
			
		}	
		Delay(250);	
	}	
}

