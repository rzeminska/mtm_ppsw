#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define ILOSC_CYKLI_MSEK 5000

void Delay(int iMilisekundy)
{
	int iLicznikPetli, iIloscMilisek;
	
	for(iIloscMilisek = 0; iIloscMilisek <= ( ILOSC_CYKLI_MSEK * iMilisekundy ); iIloscMilisek++)
	{
		iLicznikPetli++;
	}
}

int main()
{
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eKeyboardRead())
		{
			case BUTTON_1:
				LedStepRight();
			break;
			
			case BUTTON_2:
				LedStepLeft();
			break;
		
			default:
			break;				
		}
		
		Delay(250);	
	}	
}

