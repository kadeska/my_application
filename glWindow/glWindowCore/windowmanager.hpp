#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "openglwindow.hpp"
#include "../../game/core/gamecore.hpp"


class WindowManager {
public:
    WindowManager(int width, int height, const char* title);
    ~WindowManager();
    //GLFWwindow* getWindow() const;
    //GLFWwindow* window;
    OpenglWindow* window;
    GameCore* gameCore;
    GameClock* gameClock;
private:

};
