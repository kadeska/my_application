#include "mainwindow.hpp"

#include <QApplication>
#include <boost/asio.hpp>
#include <iostream>

// Defines
void init();
void do_stuff();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    do_stuff();
    return a.exec();
}

void init() {}

void do_stuff()
{
    std::cout << "Do stff!!..." << '\n';
}
