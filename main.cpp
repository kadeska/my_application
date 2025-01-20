#include "mainwindow.hpp"
//#include "glWindow/glWindowCore/openglwindow.hpp"
#include "game/core/gamecore.hpp"
#include "game/core/gameclock.hpp"

#include <QApplication>
#include <boost/asio.hpp>
#include <iostream>

// Defines

void init();
void init_game();

//GameClock gameClock;
GameClock* gameClock = nullptr;


//functions

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    init_game();
    //OpenglWindow glWindow; OpenGl window is now opened in the mainwindow actionbar.

    //delete gameClock;
    return a.exec();
}

void init() {}

void init_game()
{
    std::cout << "init game!!..." << '\n';

    gameClock = new GameClock();
    GameCore gamecore(1, true, *gameClock);
    //gameClock->start();
    gamecore.init();
}
