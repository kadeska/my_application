#include "mainwindow.hpp"
//#include "glWindow/glWindowCore/openglwindow.hpp"
#include "helper.hpp"


#include <QApplication>
#include <boost/asio.hpp>
#include <iostream>

// Defines
UsefulFunctions::StdOutput stdOut;

int Helper::progLogLevel = 3; // Default log level
int Helper::skippedLogCount = 0; // Initialize skipped log count


//functions

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    helper.log(3, "Main Function");
    stdOut.print("Testing standard output");
    std::string out = "main(argc: " + std::to_string(argc) + ", argv: [";
    for (int i = 0; i < argc; ++i) {
        out += "\"" + std::string(argv[i]) + "\"";
        if (i < argc - 1) out += ", ";  // Add a comma between arguments
    }
    out += "])";
    helper.log(2, out);

    MainWindow w;
    w.show();

    return a.exec();
}
