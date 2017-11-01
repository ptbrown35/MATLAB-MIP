/* Copyright 2017 The MathWorks, Inc. */

/**************************************
 *      BeagleBone Blue DC Motor Driver       *
 **************************************/

#include "MW_bbblue_driver.h"

/* Set Motor Speeds*/

void MW_set_motor(uint8_T index, int8_T duty, uint8_T stopAction)
{
    duty = (duty > 100 ? 100 : duty);
    duty = (duty < -100 ? -100 : duty);
	rc_set_motor(index,(duty/100.0));
    if (duty == 0)
    {
    	switch(stopAction)
    	{
    		case 1 :
    			rc_set_motor_brake(index);    	
    		break;
    		case 2 :
    			rc_set_motor_free_spin(index);
    		break;
    	}
    }
}


void MW_terminate_motor(uint8_T stopAction)
{
	rc_set_motor_all(0);
	switch(stopAction)
    	{
    		case 1 :
    			rc_set_motor_brake_all();    	
    		break;
    		case 2 :
    			rc_set_motor_free_spin_all();
    		break;
    	}
}
