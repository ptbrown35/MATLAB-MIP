#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#include "MW_bbblue_init.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Raspberry Pi
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.raspi.getDeviceAddress
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_RUNINBACKGROUND 1
#define MW_EXTMODE_CONFIGURATION TCP/IP
#define MW_EXTMODE_RUNNING on
#define MW_TARGETSERVICES_RUNNING 0.000000
#define MW_PROFILER_CONFIGURATION Disabled
#define MW_RTOS Linux
#define MW_RTOSBASERATETASKPRIORITY 40
#define MW_DETECTTASKOVERRUNS 0.000000
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_BOARDPARAMETERS_DEVICEADDRESS 192.168.7.2
#define MW_BOARDPARAMETERS_USERNAME root
#define MW_BOARDPARAMETERS_PASSWORD Ptbrown
#define MW_BOARDPARAMETERS_BUILDDIR /home/root
#define MW_RUNTIME_BUILDACTION 1
#define MW_SPI_SPI0CE0BUSSPEED 6
#define MW_SPI_SPI0CE1BUSSPEED 6
#define MW_DATAVERSION 2016.02
#define MW_MULTI_TASKING_MODE 1

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
