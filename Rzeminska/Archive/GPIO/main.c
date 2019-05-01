#include <LPC21xx.H>

#define ILOSC_CYKLI_MSEK 5000

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define S0_bm 0x10
#define S1_bm 0x40
#define S2_bm 0x20
#define S3_bm 0x80


enum KeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};
enum LedDirection {LEFT, RIGHT};

void Delay(int iMilisekundy)
{
	int iLicznikPetli, iIloscMilisek;
	
	for(iIloscMilisek = 0; iIloscMilisek <= ( ILOSC_CYKLI_MSEK * iMilisekundy ); iIloscMilisek++)
	{
		iLicznikPetli++;
	}
}


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


enum KeyboardState eKeyboardRead()
{
	if( (IO0PIN & S0_bm) == 0)
	{
		return BUTTON_0;
	}
	
	else if( (IO0PIN & S1_bm) == 0)
	{
		return BUTTON_1;
	}
	
	else if( (IO0PIN & S2_bm) == 0)
	{
		return BUTTON_2;
	}
	
	else if( (IO0PIN & S3_bm) == 0)
	{
		return BUTTON_3;
	}
		
	else
	{
		return RELEASED;
	}
}


void KeyboardInit()
{
	IO0DIR = IO0DIR & ~( S0_bm | S1_bm | S2_bm | S3_bm );	
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

