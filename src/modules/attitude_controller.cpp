# include "mbed.h"
#include "attitude_controller.h"

// Class constructor
AttitudeController::AttitudeController()
{
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
}
// Control torques (N.m) given reference angles ( rad) and current angles ( rad ) andangular velocities ( rad /s)
void AttitudeController::control( float phi_r , float theta_r , float psi_r , float phi, float theta , float psi , float p, float q, float r)
{
    tau_theta = -(theta - theta_r) * kd_att - q * kp_att;

    tau_phi = -(phi -phi_r) * kd_att - p * kp_att;

    tau_psi = -psi * kd_att - r * kp_att;
}
// Control torque (N.m) given reference angle ( rad ) and current angle ( rad ) andangular velocity ( rad /s) with given controller gains
// float AttitudeController::control_siso( float angle_r , float angle , float rate ,float kp_att , 
//     float kd_att)
// {
//     //(...)
// }