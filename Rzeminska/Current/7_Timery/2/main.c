#include "led.h"
#include "keyboard.h"
#include "timer.h"


int main()
{
  LedInit();
	InitTimer0Match0(100000);
	
	while(1)
	{
    LedStepLeft();
    WaitOnTimer0Match0();
	}
}


