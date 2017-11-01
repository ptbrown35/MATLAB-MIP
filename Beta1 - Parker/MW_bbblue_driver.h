/* Copyright 2017 The MathWorks, Inc. */

#ifndef MW_DRIVER_BBBLUE_H
#define MW_DRIVER_BBBLUE_H



#if ( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER) )
/* This will be run in Rapid Accelerator Mode */

/* Button */
#define rc_get_mode_button() (0)
#define rc_get_pause_button(a,b,c) (0)

/*LED*/
#define rc_set_led(a,b)(0)

/* Encoder */
#define getEncoderValue(a,b,c) (0)

/*Motors*/
#define MW_set_motor(a,b,c) (0)
#define MW_terminate_motor(a) (0)

/* IMU */
#define fccr_initialize_imu() (0)
#define fccr_read_accel_x() (0)
#define fccr_read_accel_y() (0)
#define fccr_read_accel_z() (0)
#define fccr_read_gyro_x() (0)
#define fccr_read_gyro_y() (0)
#define fccr_read_gyro_z() (0)
#define rc_power_off_imu() (0)

/* Barometer */
#define rc_initialize_barometer(a,b) (0)
#define rc_power_off_barometer() (0)
#define rc_read_barometer() (0)
#define rc_bmp_get_temperature() (0)
#define rc_bmp_get_pressure_pa() (0)
#define rc_bmp_get_altitude_m() (0)

#else

#include "roboticscape.h"
#include "rtwtypes.h"

/* Button*/
extern rc_button_state_t rc_get_mode_button();
extern rc_button_state_t rc_get_mode_button();

/*LED*/
extern int rc_set_led(rc_led_t led, int state);

/* Encoder */
int32_T getEncoderValue(uint8_T portNumber, uint8_T mode, int8_T in);

/*Motors*/
void MW_set_motor(uint8_T index, int8_T duty, uint8_T stopAction);
void MW_terminate_motor(uint8_T stopAction);

/* IMU */
int fccr_initialize_imu();
float fccr_read_accel_x();
float fccr_read_accel_y();
float fccr_read_accel_z();
float fccr_read_gyro_x();
float fccr_read_gyro_y();
float fccr_read_gyro_z();
extern int rc_power_off_imu() ;

/* Barometer */
extern int rc_initialize_barometer(rc_bmp_oversample_t oversample, rc_bmp_filter_t filter);
extern int rc_power_off_barometer();
extern int rc_read_barometer();
extern float rc_bmp_get_temperature();
extern float rc_bmp_get_pressure_pa();
extern float rc_bmp_get_altitude_m();

#endif


#endif
