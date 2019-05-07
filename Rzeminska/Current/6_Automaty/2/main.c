#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


enum LedState{STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};

enum LedState eLedState = STATE0;


int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		
		switch(eLedState)
		{
			case STATE0:
				LedStepLeft();
				eLedState = STATE1;
				break;
			
			case STATE1:
				LedStepLeft();
				eLedState = STATE2;
				break;
			
			case STATE2:
				LedStepLeft();
				eLedState = STATE3;
				break;
			
			case STATE3:
				LedStepRight();
				eLedState = STATE4;
				break;
			
			case STATE4:
				LedStepRight();
				eLedState = STATE5;
				break;
			
			case STATE5:
				LedStepRight();
				eLedState = STATE0;
				break;
			
		}	
		Delay(250);	
	}	
}

