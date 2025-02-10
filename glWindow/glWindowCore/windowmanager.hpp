#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "renderer.hpp"
#include "openglwindow.hpp"
#include "../../game/core/gamecore.hpp"


class WindowManager {
public:
    /**
     * @brief WindowManager
     * @param width
     * @param height
     * @param title
     * @param noqt true or false, are we uing qt?
     */
    WindowManager(int width, int height, const char* title, bool useqt);
    void gameloop_noQT();
    ~WindowManager();
    //GLFWwindow* getWindow() const;
    //GLFWwindow* window;
    OpenglWindow* window;

    GameCore* gameCore;
    // QT instance
    myGameClock_QT::QTGameClock* qt_gameClock;
    // non-qt instance
    myGameClock::GameClock* gameClock;
    Renderer* renderer;
private:

};
