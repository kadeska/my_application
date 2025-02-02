#include "windowmanager.hpp"
#include "renderer.hpp"
#include "openglwindow.hpp"

#include "../../helper.hpp"

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <filesystem>
#include <string>
#include <iostream>

//OpenglWindow* window;
//GameCore* gameCore;
//GameClock* gameClock;


WindowManager::WindowManager(int width, int height, const char* title) {
    gameClock = new GameClock(nullptr);
    gameCore = new GameCore(1, true, gameClock);
    window = new OpenglWindow(gameCore);
    //gameClock->start();
    gameCore->init();

}

WindowManager::~WindowManager() {
    //glfwDestroyWindow(window);
    //glfwTerminate();
}


int startWindow() {
    return 0;
}





