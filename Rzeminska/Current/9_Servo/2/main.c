#include "led.h"
#include "timer_interrups.h"
#include "keyboard.h"
#include "servo.h"


enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};

struct Servo sServo;


void Automat()
{
	switch(sServo.eState)
		{
			case CALLIB:
				if(eReadDetector() == INACTIVE)
				{
					LedStepRight();
				}
				else
				{
					LedStepRight();
					sServo.eState = IDLE;
					sServo.uiCurrentPosition = 0;
					sServo.uiDesiredPosition = 0;
				}
				break;
				
			case IDLE:
				if (sServo.uiCurrentPosition != sServo.uiDesiredPosition)
				{
					sServo.eState = IN_PROGRESS;
				}
				else
				{
					sServo.eState = IDLE;
				}
				break;
				
			case IN_PROGRESS:
				if (sServo.uiDesiredPosition > sServo.uiCurrentPosition)
				{
				LedStepRight();
				sServo.uiCurrentPosition++;
				}
				else if (sServo.uiDesiredPosition < sServo.uiCurrentPosition)
				{
				LedStepLeft();
				sServo.uiCurrentPosition--;
				}
				else
				{
					sServo.eState = IDLE;
				}
				
		}
}

int main ()
{
	LedInit();	
	KeyboardInit();
	DetectorInit();
	
	Timer0Interrupts_Init(200000, &Automat);

	while(1)
	{
		if(eKeyboardRead() == BUTTON_0)
		{
			sServo.eState = CALLIB;
		}
		else if(eKeyboardRead() == BUTTON_1)
		{
			sServo.uiDesiredPosition = 12;
		}
		else if(eKeyboardRead() == BUTTON_2)
		{
			sServo.uiDesiredPosition = 24;
		}
		else if(eKeyboardRead() == BUTTON_3)
		{
			sServo.uiDesiredPosition = 36;
		}
	 	
	}
}
