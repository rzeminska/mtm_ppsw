#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


enum LedState{STAY, MOVE_RIGHT};
enum LedState eLedState = STAY;
unsigned char ucStepsCounter = 0;


int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		
		switch(eLedState)
		{
			case MOVE_RIGHT:
				ucStepsCounter++;
				if(ucStepsCounter == 3)
				{
					eLedState = STAY;
					ucStepsCounter = 0;
				}
				LedStepRight();
				break;
			
			case STAY:
				if(eKeyboardRead() == BUTTON_0)
				{
					eLedState = MOVE_RIGHT;
				}
				break;
			
		}	
		Delay(250);	
	}	
}

