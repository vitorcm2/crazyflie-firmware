#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

// Mixer class
class Mixer
{
    public :
        // Class constructor
        Mixer () ;
        void arm();
        // Actuate motors with desired total trust force (N) and torques (N.m)
<<<<<<< HEAD
        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);
        void disarm();

      private:
        // Motors PWM outputs
        PwmOut motor_1, motor_2, motor_3, motor_4;
        // Angular velocities ( rad /s)
        float omega_1, omega_2, omega_3, omega_4;
        // Led's outputs
        DigitalOut redRLed, redLLed, blueLed, greenLLed, greenRLed;
        // Convert total thrust force (N) and torques (N.m) to angular
        // velocities (rad/s)
        void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);
        float control_motor(float omega);
=======
        void actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi ) ;
        void disarm();

    private:
        // Motors PWM outputs
        PwmOut motor_1 , motor_2 , motor_3 , motor_4 ;
        // Angular velocities ( rad /s)
        float omega_1 , omega_2 , omega_3 , omega_4 ;
        // Led's outputs
        DigitalOut redRLed, redLLed, blueLed, greenLLed, greenRLed;
        // Convert total thrust force (N) and torques (N.m) to angular velocities (rad/s)
        void mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi );
        float control_motor ( float omega );
>>>>>>> 3adc0fe774595bc079c53b64c240dc278a3d317e
        bool armed;
};

#endif