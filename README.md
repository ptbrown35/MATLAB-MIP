# MATLAB-MIP
### MATLAB controlled MIP

### Project Goals
* Run eduMIP examples through MATLAB Simulink
* Use Simulink's UI to simplify interfacing with the Robotics Cape
* Make simple examples for blink and basic balancing

### Roboticscape Functionality
* Raw Barometer Data: pressure, temperature, altitude
* Raw IMU Data: 3-axis acceleration, 3-axis gyro

### Example Simulations: beta/test_models
* Template (template.slx): good starting point for new MATLAB MIP simulations
* Barometer Test (barometer_test.slx): returns raw pressure, temperature, altitude
* IMU test (imu_test.slx): returns raw 3-axis acceleration, 3-axis gyro
* Complimentary Filter (complimentary_filter.slx): returns body tilt angle from filtered accel/gyro data
* MIP Balancing (mip_balance.slx): MIP balancing with user defined controllers

### Resources
* [Robotics Cape User Manual](http://strawsondesign.com/#!manual-install)
* [Robotics Cape Installer](https://github.com/StrawsonDesign/Robotics_Cape_Installer/releases)
* [Simulink Coder Support Package for BeagleBone Blue Hardware](https://www.mathworks.com/matlabcentral/fileexchange/64925-simulink-coder-support-package-for-beaglebone-blue-hardware)
* [Labview MIP](https://github.com/ktalke12/Labview-MiP)
