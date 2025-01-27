// Include GLFW
#include <GLFW/glfw3.h>
//extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <iostream>

#include "controls.hpp"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
    return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
    return ProjectionMatrix;
}


// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 5 );
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;



void computeMatricesFromInputs(GLFWwindow* window) {
    if (!window) {
        fprintf(stderr, "Error: Invalid window in computeMatricesFromInputs\n");
        return;
    }

    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    glfwSetCursorPos(window, width / 2, height / 2);

    horizontalAngle += mouseSpeed * float(width / 2 - xpos);
    verticalAngle += mouseSpeed * float(height / 2 - ypos);

    verticalAngle = glm::clamp(verticalAngle, -glm::half_pi<float>(), glm::half_pi<float>());

    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
        );

    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - glm::half_pi<float>()),
        0,
        cos(horizontalAngle - glm::half_pi<float>())
        );

    glm::vec3 up = glm::cross(right, direction);

    float adjustedSpeed = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) ? speed * 2.0f : speed;

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        position += direction * deltaTime * adjustedSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        position -= direction * deltaTime * adjustedSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        position += right * deltaTime * adjustedSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        position -= right * deltaTime * adjustedSpeed;
    }

    float FoV = initialFoV;

    ProjectionMatrix = glm::perspective(glm::radians(FoV), float(width) / float(height), 0.1f, 100.0f);
    ViewMatrix = glm::lookAt(position, position + direction, up);

    lastTime = currentTime;
}
