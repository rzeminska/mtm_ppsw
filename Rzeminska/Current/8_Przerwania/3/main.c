#include <LPC21xx.H>
#include "led.h"


#define mCOUNTER_ENABLE 0x00000001
#define mCOUNTER_RESET  0x00000002

#define mINTERRUPT_ON_MR0 0x00000001
#define mRESET_ON_MR0     0x00000002
#define mMR0_INTERRUPT    0x00000001

#define VIC_TIMER0_CHANNEL_NR 4

#define mIRQ_SLOT_ENABLE 0x00000020


void (*ptrTimer0InterruptFunction)(void);

__irq void Timer0IRQHandler()
{
	T0IR=mMR0_INTERRUPT; 	
	LedStepRight();		
	VICVectAddr=0x00; 	
}

void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void))
{     
	VICIntEnable |= (0x1 << VIC_TIMER0_CHANNEL_NR);            
	VICVectCntl0  = mIRQ_SLOT_ENABLE | VIC_TIMER0_CHANNEL_NR;  
	VICVectAddr0  =(unsigned long)Timer0IRQHandler; 	   

	T0MR0 = 15 * uiPeriod;                 	      
	T0MCR |= (mINTERRUPT_ON_MR0 | mRESET_ON_MR0);  

	T0TCR |=  mCOUNTER_ENABLE; 
	
	ptrTimer0InterruptFunction = ptrInterruptFunction;
}

int main ()
{
	unsigned int iMainLoopCtr;
	Timer0Interrupts_Init(250000, &LedStepLeft);

	while(1)
	{
	 	iMainLoopCtr++;
	}
}
