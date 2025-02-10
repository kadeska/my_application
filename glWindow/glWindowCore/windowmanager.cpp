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
#include "../../game/inventory/inventory.hpp"

//OpenglWindow* window;
//GameCore* gameCore;
//GameClock* gameClock;


WindowManager::WindowManager(int width, int height, const char* title, bool useqt) {
    window = new OpenglWindow();
    if(useqt){
        // QT based instance
        qt_gameClock = new myGameClock_QT::QTGameClock(window, nullptr);
        gameCore = new GameCore(1, true, qt_gameClock, window);
    } else {
        gameClock = new myGameClock::GameClock(window, nullptr);
        gameCore = new GameCore(1, true, gameClock, window);
    }


    //gameClock->start();
    gameCore->init();
    renderer = new Renderer();
    game::Item test("Test Item", 1);
    test.printDetails();

    game::Inventory* inv = new game::Inventory();

}

WindowManager::~WindowManager() {
    //glfwDestroyWindow(window);
    //glfwTerminate();
}


int startWindow() {
    return 0;
}





