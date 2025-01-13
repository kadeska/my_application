#include "settings_window.hpp"
#include "ui_settings_window.h"
#include "helper.hpp"
#include <iostream>

Helper helper;
namespace Background_color {
float R = 0.0f;
float G = 0.0f;
float B = 0.0f;
float A = 1.0f; // Default alpha value (fully opaque)
}

Settings_window::Settings_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings_window)
{
    ui->setupUi(this);
    Background_color::R = 0.0f;
    Background_color::G = 0.0f;
    Background_color::B = 0.0f;
    Background_color::A = 1.0f;
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


void Settings_window::on_slider_volume_valueChanged(int value)
{
    std::cout << value << '\n';
    //helper.color_add_value = value; // Using volume value for this temporary as a proof of concept.

}


void Settings_window::on_slider_R_valueChanged(int value)
{
    std::cout << value << '\n';
    Background_color::R = static_cast<float>(value) / 100.0f;;
}


void Settings_window::on_slider_G_valueChanged(int value)
{
    std::cout << value << '\n';
    Background_color::G = static_cast<float>(value) / 100.0f;;
}


void Settings_window::on_slider_B_valueChanged(int value)
{
    std::cout << value << '\n';
    Background_color::B = static_cast<float>(value) / 100.0f;;
}


void Settings_window::on_slider_A_valueChanged(int value)
{
    std::cout << value << '\n';
    Background_color::A = static_cast<float>(value) / 100.0f;;
}


void Settings_window::on_Set_volume_clicked()
{

}


void Settings_window::on_Set_R_clicked()
{

}


void Settings_window::on_Set_G_clicked()
{

}


void Settings_window::on_Set_B_clicked()
{

}


void Settings_window::on_Set_A_clicked()
{

}

