#include "settings_window.hpp"
#include "ui_settings_window.h"
#include "helper.hpp"
#include <iostream>

Helper helper;

Settings_window::Settings_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings_window)
{
    ui->setupUi(this);
}

Settings_window::~Settings_window()
{
    delete ui;
}

void Settings_window::on_checkBox_sound_checkStateChanged(const Qt::CheckState &arg1)
{

}


void Settings_window::on_checkBox_debug_checkStateChanged(const Qt::CheckState &arg1)
{
    std::cout << arg1 << '\n';
}

void Settings_window::on_volume_actionTriggered(int action)
{
    //std::cout << action << '\n';
}


void Settings_window::on_testbutton_clicked()
{

}


void Settings_window::on_volume_valueChanged(int value)
{
    std::cout << value << '\n';
    helper.color_add_value = value; // Using volume value for this temporary as a proof of concept.
}

