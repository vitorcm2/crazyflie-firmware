#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

//Constantes
const float a1 = 1.128e-09;
const float a2 = 1.269e-07;
const float kl = 1.526e-08;
const float kd = 1.061e-10;

const float ele = 33e-3;


const float wc = 5.0;
const float dt = 0.002;
const float alpha = (wc*dt)/(1+wc*dt);

const float ts = 0.3;
const float up = 0.005;
const float zeta = abs(log(up))/sqrt(pow(log(up),2)+pow(pi,2));
const float wn = 4/(zeta*ts);

const float kp_att = wn*wn;
const float kd_att =2*zeta*wn;


#endif