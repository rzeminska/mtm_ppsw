#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define ILOSC_CYKLI_MSEK 5000

enum KeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

void Delay(int iMilisekundy)
{
	int iLicznikPetli, iIloscMilisek;
	
	for(iIloscMilisek = 0; iIloscMilisek <= ( ILOSC_CYKLI_MSEK * iMilisekundy ); iIloscMilisek++)
	{
		iLicznikPetli++;
	}
}

enum LedState{LED_LEFT, LED_RIGHT};

enum LedState eLedState = LED_LEFT;


int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eLedState)
		{
			case LED_LEFT:
				eLedState = LED_RIGHT;
				LedStepRight();
				break;
			
			case LED_RIGHT:
				eLedState = LED_LEFT;
				LedStepLeft();
				break;
			
		}		
		Delay(250);	
	}	
}

