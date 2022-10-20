#include "attitude_estimator.h"
#include <cmath>
#include "mbed.h"

// Class constructor
AttitudeEstimator::AttitudeEstimator():imu( IMU_SDA , IMU_SCL )
{
    // Euler angles ( rad)
    phi = 0, theta = 0 , psi = 0;
    // Angular velocities ( rad /s)
    p =0 , q = 0, r = 0;

    p_bias = 0;

}

// Initialize class
void AttitudeEstimator::init()
{
    imu.init();
    // A calibração
    for( int i = 0; i<500; i++){
        imu.read();
        p_bias += imu.gx/500.0;
        q_bias += imu.gy/500.0;
        r_bias += imu.gz/500.0;
        wait(dt);
    }

}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator::estimate()
{
    imu.read();
    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;

    // Acelerometro
    float phi_a = atan2(-imu.ay,-imu.az);
    float theta_a = atan2(imu.ax,-sign(imu.az)*sqrt(pow(imu.az,2)+pow(imu.ay,2)));

    // Giroscopio
    float phi_g = phi + (p + sin(phi) * tan(theta)*q + cos(phi) * tan(theta)*r)*dt;
    float theta_g = theta + (cos(phi)*q - sin(phi)*r)*dt;
    float psi_g = psi + (sin(phi) * (1/cos(theta))*q + cos(phi) * (1/cos(theta)*r))*dt;

    phi = alpha*phi_a + (1.0-alpha)*phi_g;
    theta = alpha*theta_a + (1.0-alpha)*theta_g;
    psi = psi_g;
}


float AttitudeEstimator::sign(float x)
{
    if (x <0)
    {
        return -1;
    }
    else 
    {
        return 1;
    }
}