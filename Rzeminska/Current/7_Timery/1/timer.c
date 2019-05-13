#include <LPC21xx.H>
#include "timer.h"

#define ENABLE_bm (1<<0)
#define RESET_bm (1<<1)

#define UsToClk 15

void InitTimer0()
{
	T0TCR = ENABLE_bm | RESET_bm;
	T0TCR = T0TCR & ~RESET_bm;
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR = T0TCR | RESET_bm;
	T0TCR = T0TCR & ~RESET_bm;
	
	while(T0TC < uiTime*UsToClk)
	{
	}
}

