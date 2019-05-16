#include <LPC21xx.H>
#include "servo.h"
#include "led.h"
#include "timer_interrups.h"

#define DETECTOR_bm (1<<10)



struct Servo sServo;


void ServoInit(unsigned int uiServoFrequency)
{
	LedInit();
	DetectorInit();
	Timer0Interrupts_Init((200000/ uiServoFrequency), &Automat);
	ServoCallib();
}

void ServoCallib(void)
{
	sServo.eState = CALLIB;
}

void ServoGoTo(unsigned int uiPosition)
{
	sServo.uiDesiredPosition = uiPosition;
}

void DetectorInit()
{
	IO0DIR = IO0DIR & (~DETECTOR_bm);
}

enum DetectorState eReadDetector(void)
{
	if( (IO0PIN & DETECTOR_bm) == 0)
	{
		return ACTIVE;
	}
	return INACTIVE;
}



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
