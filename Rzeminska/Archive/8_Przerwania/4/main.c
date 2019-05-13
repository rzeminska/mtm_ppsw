#include "led.h"
#include "timer_interrups.h"


int main ()
{
	unsigned int iMainLoopCtr;
	Timer0Interrupts_Init(250000, &LedStepLeft);

	while(1)
	{
	 	iMainLoopCtr++;
	}
}
