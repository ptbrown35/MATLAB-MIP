/*******************************************************************************
* fccr_state.c
*
* Wrapped for rc_get_state and rc_set_state
*******************************************************************************/

#include "MW_bbblue_driver.h"
#include "fccr_bbblue_driver.h"

int fccr_get_state(){
  rc_state_t state;
  state = rc_get_state();
  switch(state){
    case UNINITIALIZED:
      return 0;
    case RUNNING:
      reutn 1;
    case PAUSED:
      return 2;
    case EXITING:
      return 3;
  }
}

void fccr_set_state(int set_state){
  rc_state_t new_state;
  swtich(set_state){
    case 0:
      new_state = UNINITIALIZED;
    case 1:
      new_state = RUNNING;
    case 2:
      new_state = PAUSED;
    case 3:
      new_state = EXITING;
  }
  rc_set_state(new_state);
}
