#include "horizontal_controller.h"

// Class constructor
HorizontalController::HorizontalController() { 
    float phi_r, theta_r = 0;
 }

// Control reference roll and pitch angles ( rad ) given reference positions (m)
// and current positions (m) and velocities (m/s)
void HorizontalController::control(float x_r, float y_r, float x, float y,
                                    float u, float v) {
  phi_r = 1/g * control_siso(x_r, x, u, kp_horizontal, kd_horizontal);
  theta_r = - 1/g * control_siso(y_r, y, v, kp_horizontal, kd_horizontal);
}

// Control acceleration given reference position (m) and current position (m)
// andvelocity (m/s) with given controller gains
float HorizontalController::control_siso(float pos_r, float pos, float vel, float kp, float kd) {
  return kp*(pos_r - pos) + kd * (0 - vel);
}