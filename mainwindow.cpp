#include "mainwindow.hpp"
#include "helper.hpp"
#include "ui/ui_mainwindow.h"
//#include "glWindow/glWindowCore/openglwindow.hpp"
#include "glWindow/glWindowCore/windowmanager.hpp"
#include "settings_window.hpp"
#include "game/core/gamecore.hpp"


#include <iostream>

WindowManager* myglWindow;


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
    helper.log(3, "MainWindow()");
}

MainWindow::~MainWindow()
{
    helper.log(3, "Cleaning MainWindow");
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    //std::cout << "Save triggered...\n";
    helper.log(3, "Save Triggered . . . ");
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
    helper.log(3, "OpenGL Window Triggered");
    this->hide();

    // Create GameClock
    //GameClock* gameClock = new GameClock();

    // Create GameCore
    //GameCore* core = new GameCore(1, true, gameClock);
    //core->init();

    createWindow();

    std::cout << "GL Window closed. Returning to Main Window...\n";
    this->show();
}

void MainWindow::createWindow(){
    // Create WindowManager

    try {
        // call function to start window
        //
        // put this inside a while loop ??
        //
        //
        //startWindow();
        myglWindow = new WindowManager(600, 600, "testing");

    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize window: " << e.what() << std::endl;
        //delete window;
        //delete core;
        //delete gameClock;
        this->show();
        return;
    }
}




void MainWindow::on_actionSettings_triggered()
{
    std::cout << "Open Settings triggered...\n";
    //settingswindow = new Settings_window(this);
    settingswindow.show();
}


void MainWindow::on_launchButton_clicked()
{
    helper.log(3, "Launch Button");
    createWindow();
}


void MainWindow::on_settingsButton_clicked()
{
    helper.log(3, "Settings Button");
    settingswindow.show();
}


void MainWindow::on_editorButton_clicked()
{
    helper.log(3, "Editor Button");
}

