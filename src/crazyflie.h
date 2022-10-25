#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/pin_names.h"
#include "utils/parameters.h"

// Crazyflie 2.0 hardware abstraction layer
// #include "drivers/mpu9250.h"    // IMU sensor

// Flow deck hardware abstraction layer
// #include "drivers/vl53l0x.h"    // Range sensor
// #include "drivers/pmw3901.h"    // Optical flow sensor

// Crazyflie 2.1 hardware abstraction layer
#include "drivers/bmi088.h"     // IMU sensor

// Flow deck v2 hardware abstraction layer
#include "drivers/vl53l1x.h"    // Range sensor
#include "drivers/pmw3901.h"    // Optical flow sensor

// Include Mixer Class
#include "modules/mixer.h"

// Include Attitude Estimator Class
#include "modules/attitude_estimator.h"

// Include Attitude Estimator Class
#include "modules/attitude_controller.h"

#endif