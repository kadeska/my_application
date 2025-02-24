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
//bool enable_QT;


//functions

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // this funtionality is broken at the moment, I need to make my own custom timer class.
    if (argc > 1 && std::string(argv[1]) == "NO_QT") {
        helper.log(3, "NO_QT");
        helper.enable_QT = false;
        helper.log(3, "Main Function");
        stdOut.print("Testing standard output");
        std::string out = "main(argc: " + std::to_string(argc) + ", argv: [";
        for (int i = 0; i < argc; ++i) {
            out += "\"" + std::string(argv[i]) + "\"";
            if (i < argc - 1) out += ", ";  // Add a comma between arguments
        }
        out += "])";
        helper.log(2, out);


        // Call window manager to create openGL window.
        glwin = new WindowManager(600, 600, "testing", false);
        return 0;
    }

    helper.enable_QT = true;
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

void print(){

}
