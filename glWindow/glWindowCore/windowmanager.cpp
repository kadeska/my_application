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

#include "../../game/inventory/item.hpp"

//OpenglWindow* window;
//GameCore* gameCore;
//GameClock* gameClock;


WindowManager::WindowManager(int width, int height, const char* title) {
    window = new OpenglWindow();
    gameClock = new GameClock(nullptr);
    gameCore = new GameCore(1, true, gameClock, window);
    //gameClock->start();
    gameCore->init();
    game::Item test("Test Item");
    test.printDetails();

}

WindowManager::~WindowManager() {
    //glfwDestroyWindow(window);
    //glfwTerminate();
}


int startWindow() {
    return 0;
}





