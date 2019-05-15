#include <LPC21xx.H>
#include "servo.h"


#define DETECTOR_bm (1<<10)


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


