README.TXT

. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
Parker Brown Updates

* Modified MW_bbblue_driver.h to include roboticscape functions for the barometer and IMU.
* Created bbblueBarometer.m block to interface Simulink with the roboticscape barometer. The oversample rate and filter coefficient are user selectable.
* Developing bbblueIMU.m, bbblueIMU_no_obj.m, and bbblueIMU_obj.m to attempt to get accelerometer and gyroscope data from the bbblue. None of them compile successfully and this is where I could use the help.
	- bbblueIMU.m has parts of bbblueIMU_no_obj.m and bbblueIMU_obj.m combined and is my working copy.
	- bbblueIMU_no_obj.m attempts to create the conf and data stucts as local to setupImpl
	-  bbblueIMU_obj.m attempts to create the conf and data stucts within setupImpl as properties of the class (obj)
* Developing fccr_bbblueIMU.m as an attempt to keep the c structs within a c wrapper (fccr_imu.c) and only pass simple data types to/from Simulink
	- fccr_imu.c is still under development and wil not compile yet
* baro_test.slx and imu_test.slx are example models for the Barometer and IMU blocks

. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

To test the BeagleBone Blue driver blocks, perform the following tasks

1) Install R2017b MATLAB and Simulink. Make sure to Install Embedded coder.
2) Install Simulink Support package for Raspberry Pi.
3) Upon Installing the Raspberry Pi support package, execute the following command in the MATLAB command prompt to get the location of the support package.
	>> location = codertarget.raspi.internal.getSpPkgRootDir
4) cd to 'location'
5) copy the following files 
	1) Copy the +beagleboneblue folder to 'location'
	2) Copy the 'beaglebonebluelib' library file to 'location/blocks'
	3) Copy the .h files to 'location/include'
	4) Copy the .c files to 'location/src'
	5) Copy and replace the raspberrypi_Attributeinfo.xml in 'location/registry/attributes'
6) In the MATLAB command line execute 
	>> rehash toolboxcache
7) To view the blocks, type 'beaglebonebluelib' in command line to open the lib.
8) To use the blocks, create a simulink model for Raspberry Pi, provide the IP address, Username and Password of your BeagleBone Blue
9) Add the required blocks from the beagleboneblue lib (These blocks will not be visible in the Simulink browser. You need to add them directly from the library)
10) Press Deploy to hardware to get the model built and downloaded onto you BeagleBone Blue.

This is a beta release. kindly refrain from sharing these source file. 
