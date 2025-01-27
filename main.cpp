#include "mainwindow.hpp"
//#include "glWindow/glWindowCore/openglwindow.hpp"
#include "helper.hpp"


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
    helper.log("Main Function");
    std::string out = "main(argc: " + std::to_string(argc) + ", argv: [";
    for (int i = 0; i < argc; ++i) {
        out += "\"" + std::string(argv[i]) + "\"";
        if (i < argc - 1) out += ", ";  // Add a comma between arguments
    }
    out += "])";
    helper.log(out);
    return a.exec();
}
