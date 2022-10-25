#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
// Define red LED (right) as digital output object
DigitalOut led(LED_RED_R,!false);
// Define motor 1 as PWM output object
PwmOut motor(MOTOR1);

// Define all motors as PWM objects

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    // Blink LED every second
    
    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true) 
    {

        motor = 0.3;
        wait(7);
        motor = 0;
        wait(7);
        
    }
}
