# MATLAB-MIP
MATLAB controlled MIP

### Project Goals
* Run eduMIP examples through MATLAB Simulink
* Use Simulink's UI to simplify interfacing with the Robotics Cape
* Make simple examples for blink and basic balancing

### roboticscape.h functions
**Wrapped**
* rc_initialize
* rc_set_led
* rc_cleanup

**Need to be wrapped**
* rc_get_state
* rc_set_state
* rc_get_led
* rc_blink_led
* rc_get_pause_button
* rc_get_pause_button_state
* rc_set_pause_pressed_func
* rc_set_pause_released_func
* rc_get_mode_button
* rc_set_mode_pressed_func
* rc_get_mode_buttom_state
* rc_set_mode_released_func
* rc_set_motor
* rc_enable_motors
* rc_disable_motors
* rc_set_motor_free_spin
* rc_set_motor_brake
* rc_get_encoder_pos
* rc_set_encoder_pos
* rc_battery_voltage
* rc_dc_jack_voltage
* rc_adc_volt
* rc_enable_servo_power_rail
* rc_disable_servo_power_rail
* rc_send_servo_pulse_us
* rc_send_servo_pulse_normalized
* rc_initialize_barometer
* rc_read_barometer
* rc_power_off_barometer
* i2c, SPI, dsm, imu, uart

**In Progress**
* rc_initialize
* rc_set_led
* rc_cleanup
* rc_get_state
* rc_set_state
* rc_get_led
* rc_blink_led
* rc_initialize_barometer
* rc_read_barometer
* rc_power_off_barometer

### Resources
* Robotics Cape Installer: https://github.com/StrawsonDesign/Robotics_Cape_Installer/releases
