<<<<<<< HEAD
#include "mbed.h"
#include "crazyflie.h"


=======
# include "mbed.h"
# include "crazyflie.h"
>>>>>>> 3adc0fe774595bc079c53b64c240dc278a3d317e
// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est ;
AttitudeController att_cont ;

// Ticker objects
Ticker tic ;
// Interrupt flag and counter variables
bool flag ;
// Callback functions
void callback() { flag = true ; }
// Main program
int main()
{
    // Set references
<<<<<<< HEAD
    float f_t = 0.8*m*g;
=======
    float f_t = m*g;
>>>>>>> 3adc0fe774595bc079c53b64c240dc278a3d317e
    float phi_r = 0.0;
    float theta_r = 0.0;
    float psi_r = 0.0;
    // Initialize estimators objects
    att_est.init();
    // Initialize interrupts
<<<<<<< HEAD
    tic.attach(&callback, dt);
    // Arm motors and run controller while stable
    mixer.arm();
    while (abs(att_est.phi) <= pi / 4.0 && abs(att_est.theta) <= pi / 4.0 &&
           abs(att_est.p) <= 4.0 * pi && abs(att_est.q) <= 4.0 * pi &&
           abs(att_est.r) <= 4.0 * pi) {
      if (flag) {
        flag = false;
        att_est.estimate();
        att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.theta,
                         att_est.psi, att_est.p, att_est.q, att_est.r);
        mixer.actuate(f_t, att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);
      }
    }
    // Disarm motors and end program
    mixer.disarm() ;
    while(true ) ;
=======
    tic.attach(&callback , dt);
    // Arm motors and run controller while stable
    mixer.arm();
    while(abs( att_est.phi ) <= pi /4.0 && abs( att_est.theta ) <= pi /4.0 && 
    abs(att_est.p) <= 4.0* pi && abs( att_est.q) <= 4.0* pi && abs( att_est.r) <= 4.0*pi)
    {
        if ( flag )
        {
        flag = false ;
        att_est.estimate() ;
        att_cont.control(phi_r , theta_r ,psi_r , att_est.phi , att_est.theta , att_est.psi , att_est.p, att_est.q, att_est.r);
        mixer.actuate(f_t ,0.0 , att_cont.tau_theta ,0.0);
        }
    }
    // Disarm motors and end program
    mixer.disarm () ;
    while( true ) ;
>>>>>>> 3adc0fe774595bc079c53b64c240dc278a3d317e
}