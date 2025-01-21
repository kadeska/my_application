#include "mainwindow.hpp"
#include "ui/ui_mainwindow.h"
#include "glWindow/glWindowCore/openglwindow.hpp"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    std::cout << "Save triggered...\n";
}


// Game window
/**
 * @brief MainWindow::on_actionGL_Window_triggered
 *
 * This is where the game window will be triggered.
 * We will make a ref to gameCore which will kickoff everything.
 *
 */
void MainWindow::on_actionGL_Window_triggered()
{
    std::cout << "Open GL Window triggered...\n";
    this->hide();

    // create ref for gameClock
    GameClock gameClock;

    // create ref for gameCore
    GameCore gamecore(1, true, gameClock);
    gamecore.init();
    OpenglWindow glWindow; //game window gets created here
    this->setVisible(true);
}


void MainWindow::on_actionSettings_triggered()
{
    std::cout << "Open Settings triggered...\n";
    //settingswindow = new Settings_window(this);
    settingswindow.show();
}

