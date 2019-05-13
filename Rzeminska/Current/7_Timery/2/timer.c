#include <LPC21xx.H>
#include "timer.h"

#define ENABLE_bm (1<<0)
#define RESET_bm (1<<1)

#define INTONMR0_bm (1<<0)
#define RESET_ON_MR0_bm (1<<1)
#define MR0INT_bm (1<<0)

#define US_TO_CLK 15

void InitTimer0()
{
	T0TCR = ENABLE_bm | RESET_bm;
	T0TCR = T0TCR & ~RESET_bm;
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR = T0TCR | RESET_bm;
	T0TCR = T0TCR & ~RESET_bm;
	
	while(T0TC != (uiTime*US_TO_CLK))
	{
	}
}

void InitTimer0Match0(unsigned int iDelayTime){
	
	T0MR0 = iDelayTime * US_TO_CLK;
	T0MCR = INTONMR0_bm | RESET_ON_MR0_bm;
	InitTimer0();
}


void WaitOnTimer0Match0(){
	
	while((T0IR & MR0INT_bm) == 0){
	}
	T0IR = MR0INT_bm;
}

