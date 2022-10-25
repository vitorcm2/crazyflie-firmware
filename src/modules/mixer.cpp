#include "mixer.h"

// Checks if variable is > 0
float sqrtOrZero(float number)
{
    if(number > 0.0){
        return sqrtf(number);
    }
    else{
        return 0.0;
    }
}

// Class constructor
Mixer::Mixer(): motor_1(MOTOR1), motor_2( MOTOR2 ), motor_3( MOTOR3 ) ,motor_4( MOTOR4 ), redRLed(LED_RED_R,!false), redLLed(LED_RED_L,!false), blueLed(LED_BLUE_L,false),
 greenRLed(LED_GREEN_R,false), greenLLed(LED_GREEN_L,false)
{
  motor_1.period(1.0 / 500.0);
  motor_2.period(1.0 / 500.0);
  motor_3.period(1.0 / 500.0);
  motor_4.period(1.0 / 500.0);
  motor_1 = 0.0;
  motor_2 = 0.0;
  motor_3 = 0.0;
  motor_4 = 0.0;
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer::actuate(float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    if(armed){
        mixer(f_t,tau_phi,tau_theta,tau_psi);
        motor_1 = control_motor(omega_1);
        motor_2 = control_motor(omega_2);
        motor_3 = control_motor(omega_3);
        motor_4 = control_motor(omega_4);
    }
}

// Convert total trust force (N) and torques (N.m) to angular velocities ( rad /s)
void Mixer::mixer( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    // Convert desired angular velocity ( rad /s) to PWM signal (%)
    omega_1 = sqrtOrZero(((1.0/(4.0*kl))*f_t) - ((1.0/(4.0*kl*ele))*tau_phi) - ((1.0/(4.0*kl*ele))*tau_theta) - ((1.0/(4.0*kd))*tau_psi));
    omega_2 = sqrtOrZero(((1.0/(4.0*kl))*f_t) - ((1.0/(4.0*kl*ele))*tau_phi) + ((1.0/(4.0*kl*ele))*tau_theta) + ((1.0/(4.0*kd))*tau_psi));
    omega_3 = sqrtOrZero(((1.0/(4.0*kl))*f_t) + ((1.0/(4.0*kl*ele))*tau_phi) + ((1.0/(4.0*kl*ele))*tau_theta) - ((1.0/(4.0*kd))*tau_psi));
    omega_4 = sqrtOrZero(((1.0/(4.0*kl))*f_t) + ((1.0/(4.0*kl*ele))*tau_phi) - ((1.0/(4.0*kl*ele))*tau_theta) + ((1.0/(4.0*kd))*tau_psi));
}

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer::control_motor( float omega )
{
    return a2* omega * omega + a1 * omega;
}

void Mixer::arm(){
    redLLed = !redLLed;
    redRLed = !redRLed;
    greenLLed = !greenLLed;
    greenRLed = !greenRLed;
    armed = true;
}

void Mixer::disarm(){
    armed = false;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
    redLLed = !redLLed;
    redRLed = !redRLed;
    greenLLed = !greenLLed;
    greenRLed = !greenRLed;
}
