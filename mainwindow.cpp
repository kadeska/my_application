#include "mainwindow.hpp"
#include "ui_mainwindow.h"
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

void MainWindow::on_actionOpen_triggered()
{
    std::cout << "Open triggered...\n";
    // open new window
    //settingswindow = new Settings_window(this);
    settingswindow.show();
}


void MainWindow::on_actionSave_triggered()
{
    std::cout << "Save triggered...\n";
}

