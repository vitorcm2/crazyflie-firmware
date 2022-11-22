#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

// Attitude estimator class
class AttitudeEstimator
{
public :
// Class constructor
AttitudeEstimator();
// Initialize class
void init();
// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void estimate();
// Função (x>0)-(x<0)
float sign(float x);
// Euler angles ( rad)
float phi , theta , psi;
// Angular velocities ( rad /s)
float p, q, r;
private :
// IMU sensor object
BMI088 imu;
float p_bias,q_bias,r_bias;

};

#endif