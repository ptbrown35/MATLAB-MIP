/* Copyright 2017 The MathWorks, Inc. */

/**************************************
 *      BeagleBone Blue Encoder Driver       *
 **************************************/

#include "MW_bbblue_driver.h"
#include "rc_usefulincludes.h"

// Get encoder value
int32_t getEncoderValue(uint8_T channelNumber,uint8_T mode,int8_T in)
{
    static int32_T oldResult[4];
    int32_T newResult;
    int32_T result;
    
    switch(mode)
    {
        case 1:
            newResult = rc_get_encoder_pos(channelNumber);
            result = newResult;
            break;
        case 2:
             newResult = rc_get_encoder_pos(channelNumber);
             result = newResult - oldResult[channelNumber];
             oldResult[channelNumber] = newResult;
             break;
        case 3:
              newResult = rc_get_encoder_pos(channelNumber);
              result = newResult - oldResult[channelNumber];
              if(in != 0)
              {
               oldResult[channelNumber] = newResult;
              }
              break;
    }
    printf("Mode %d: Encoder on %d channel - %d\n", mode, channelNumber, result);
    
    return result;
}
