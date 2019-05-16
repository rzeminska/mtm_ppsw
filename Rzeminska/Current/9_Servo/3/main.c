#include "led.h"
#include "timer_interrups.h"
#include "keyboard.h"
#include "servo.h"
#include "timer.h"



int main ()
{
	LedInit();	
	KeyboardInit();
	ServoInit(50);
	

	while(1)
	{
    switch(eKeyboardRead())
		{
      case BUTTON_0:
        ServoCallib();
        break;
      case BUTTON_1:
        ServoGoTo(15);
        break;
      case BUTTON_2:
        ServoGoTo(30);
        break;
      case BUTTON_3:
        ServoGoTo(50);
        break;
      default:
        break;
	 	}
	}
}
