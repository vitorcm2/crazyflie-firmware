#include "crazyflie.h"
#include "mbed.h"


// Define motor as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor(float omega) {
  return a2* omega * omega + a1 * omega;
}

// Main program
int main() {
  // Set PWM frequency to 500 Hz
  // motor.period(1.0/500.0) ;

  // End of program
  while (true) {
    // Turn on motor with 1.000 rad /s for 0.5s
    motor1 = control_motor(1000);
    motor2 = control_motor(2000);
    motor3 = control_motor(1000);
    motor4 = control_motor(2000);

  }
}
