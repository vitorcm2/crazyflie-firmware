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
const float a1 = 1.128e-9;
const float a2 = 1.269e-07;
const float kl = 1.526e-08;
const float kd = 1.061e-10;

const float ele = 33e-3;

const float wc = 5.0;
const float dt = 0.002;
const float alpha = (wc*dt)/(1+wc*dt);

// Ganho rolagem (phi) e inclinacao (theta)
const float ts = 0.3;
const float up = 0.005;
const float zeta = abs(log(up))/sqrt(pow(log(up),2)+pow(pi,2));
const float wn = 4.0/(zeta*ts);

const float kp_att = wn*wn;
const float kd_att =2.0*zeta*wn;

// Ganho guinagem (psi)
const float ts_2 = 0.6;
const float wn_2 = 4.0/(zeta*ts_2);

const float kp_att_2 = wn_2*wn_2;
const float kd_att_2 =2.0*zeta*wn_2;

//Vertical estimator
const float dt_range = 0.05;
const float zeta_vert = sqrt(2.0)/2.0;
const float wc_vert = 10.0;
const float l_vert1 = wc_vert * wc_vert;
const float l_vert2 = 2.0 * zeta_vert * wc_vert;

// Ganho rolagem (phi) e inclinacao (theta)
const float ts_vert = 2.0;
const float up_vert = 0.005;
const float zeta_vert2 = abs(log(up_vert))/sqrt(pow(log(up_vert),2)+pow(pi,2));
const float wn_vert = 4.0/(zeta_vert2*ts_vert);

const float kp_vert = wn_vert * wn_vert;
const float kd_vert = 2.0 * zeta_vert2 * wn_vert;

// Horizontal estimator
const float sigma = 2.0 * tan((42.0*pi/180.0)/2.0)/(420.0 * dt);
const float ganho_observador = 50.0;

// Ganho horizontal
const float ts_horizontal = 2.0;
const float up_horizontal = 0.005;
const float zeta_horizontal = abs(log(up_horizontal))/sqrt(pow(log(up_horizontal),2)+pow(pi,2));
const float wn_horizontal = 4.0/(zeta_horizontal*ts_horizontal);

const float kp_horizontal =  wn_horizontal * wn_horizontal;
const float kd_horizontal =  2.0 * zeta_horizontal * wn_horizontal;

//Lab Final
const float tsub = 10.0;
const float tvoo = 2.0;
const float tdesc = 10.0;


#endif