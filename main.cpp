#include "mainwindow.hpp"
//#include "glWindow/glWindowCore/openglwindow.hpp"
#include "helper.hpp"
#include "glWindow/glWindowCore/windowmanager.hpp"


#include <QApplication>
#include <boost/asio.hpp>
#include <iostream>

// Defines
UsefulFunctions::StdOutput stdOut;

int Helper::progLogLevel = 3; // Default log level
int Helper::skippedLogCount = 0; // Initialize skipped log count

WindowManager* glwin;


//functions

int main(int argc, char *argv[])
{
    //std::string arg = argv[1];
    if (argc > 1 && std::string(argv[1]) == "NO_QT") {
        helper.log(3, "NO_QT");
        glwin = new WindowManager(600, 600, "testing");
        return 0;
    }

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

    // Testing out my template
    // Printer<char*> strprint;
    // strprint.print("Hello world!", 3);
    // Printer<int> printer;
    // printer.print(100, 3);


    MainWindow w;
    w.show();

    return a.exec();
}
