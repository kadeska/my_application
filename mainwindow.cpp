#include "mainwindow.hpp"
#include "helper.hpp"
#include "ui/ui_mainwindow.h"
//#include "glWindow/glWindowCore/openglwindow.hpp"
#include "glWindow/glWindowCore/windowcreation.hpp"
#include "settings_window.hpp"
#include "game/core/gamecore.hpp"


#include <iostream>


/**
* @brief MainWindow::MainWindow
        * @param parent
            *
            * This is the main window where you can launch the game window from
            *
            */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    helper.log("MainWindow()");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    //std::cout << "Save triggered...\n";
    helper.log("Save Triggered . . . ");
}


// Game window
/**
 * @brief MainWindow::on_actionGL_Window_triggered
 *
 * This is where the game window will be triggered.
 * We will make a ref to gameCore and game clock,
 * then create the window which will kickoff
 * everything, using gameCore.
 *
 */
void MainWindow::on_actionGL_Window_triggered()
{
    // std::cout << "Open GL Window triggered...\n";
    helper.log("OpenGL Window Triggered");
    this->hide();

    // Create GameClock
    GameClock* gameClock = new GameClock();

    // Create GameCore
    GameCore* core = new GameCore(1, true, gameClock);
    core->init();

    // Create WindowCreation
    WindowCreation* window = new WindowCreation(core);
    try {
        window->initializeWindow(800, 600, "OpenGL Window");
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize window: " << e.what() << std::endl;
        delete window;
        delete core;
        delete gameClock;
        this->show();
        return;
    }

    // Create BaseModel
    BaseModel* model = new BaseModel();

    try {
        // Start render loop
        window->startRenderLoop(model);
    } catch (const std::exception& e) {
        std::cerr << "Error during render loop: " << e.what() << std::endl;
    }

    // Clean up
    delete model;
    delete window;
    delete core;
    delete gameClock;

    std::cout << "GL Window closed. Returning to Main Window...\n";
    this->show();
}



void MainWindow::on_actionSettings_triggered()
{
    std::cout << "Open Settings triggered...\n";
    //settingswindow = new Settings_window(this);
    settingswindow.show();
}

