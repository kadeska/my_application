#include "mainwindow.hpp"
//#include "glWindow/glWindowCore/openglwindow.hpp"


#include <QApplication>
#include <boost/asio.hpp>
#include <iostream>

// Defines


//functions

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << "Debug out: main function \n";

    //init_game(); // this should only be called when the game window is opened.

    //OpenglWindow glWindow; OpenGl window is now opened in the mainwindow actionbar.

    //delete gameClock;
    std::cout << "exec \n";
    return a.exec();
}
