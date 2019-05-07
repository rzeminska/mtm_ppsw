#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


enum LedState{MOVE_LEFT, MOVE_RIGHT};
enum LedState eLedState = MOVE_LEFT;
unsigned char ucStepsCounter = 0;


int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		
		switch(eLedState)
		{
			case MOVE_LEFT:
				ucStepsCounter++;
				if(ucStepsCounter == 3)
				{
					eLedState = MOVE_RIGHT;
				}
				LedStepLeft();
				break;
			
			case MOVE_RIGHT:
				ucStepsCounter--;
				if(ucStepsCounter == 0)
				{
					eLedState = MOVE_LEFT;
				}
				LedStepRight();
				break;
			
		}	
		Delay(250);	
	}	
}

