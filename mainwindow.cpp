#include "mainwindow.hpp"
#include "ui/ui_mainwindow.h"
#include "glWindow/glWindowCore/openglwindow.hpp"
#include "settings_window.hpp"
#include <iostream>

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


void MainWindow::on_actionGL_Window_triggered()
{
    std::cout << "Open GL Window triggered...\n";
    this->hide();
    OpenglWindow glWindow;
    this->setVisible(true);
}


void MainWindow::on_actionSettings_triggered()
{
    std::cout << "Open Settings triggered...\n";
    //settingswindow = new Settings_window(this);
    settingswindow.show();
}

