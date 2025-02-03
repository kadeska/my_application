#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include "../../game/core/gamecore.hpp"


void computeMatricesFromInputs(GLFWwindow* window);
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif
