#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include "../../game/core/gamecore.hpp"
#include "../../glWindow/gl/model/basemodel.hpp"

class WindowCreation {
public:
    WindowCreation(GameCore* gameCore);
    ~WindowCreation();

    void initializeWindow(int width, int height, const std::string& title);
    void startRenderLoop(BaseModel* model);

private:
    GameCore* gameCore;
    GLFWwindow* window;

    void setupOpenGL();
    void terminate();
};
