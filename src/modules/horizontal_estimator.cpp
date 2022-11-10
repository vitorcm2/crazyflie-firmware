#include "horizontal_estimator.h"
#include <cmath>

// Class constructor
HorizontalEstimator::HorizontalEstimator() : flow(PA_7, PA_6, PA_5, PB_4) {
  float x, y, u, v = 0;
}

// Initialize class
void HorizontalEstimator::init() {
    flow.init();
}

// Predict horizontal positions and velocities from model
void HorizontalEstimator ::predict(float phi, float theta) {
    x = x + u*dt;
    y = y + v*dt;
    u = u + g * theta * dt;
    v = v - g * phi * dt;
}

// Correct horizontal velocities with measurements
void HorizontalEstimator::correct(float phi, float theta, float p, float q, float z) {
  // Correct horizontal velocities with measurements
    float den = cos(phi) * cos(theta);
    if (den > 0.5) {
      float d = z/den;
      flow.read();
      float u_m = (sigma * flow.px + q) * d;
      float v_m = (sigma * flow.py - p) * d;
      u = u + ganho_observador * dt * (u_m - u);
      v = v + ganho_observador * dt * (v_m - v);
    }
}