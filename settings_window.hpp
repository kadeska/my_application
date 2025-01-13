#pragma once

#include <QDialog>

namespace Ui {
class Settings_window;
}

class Settings_window : public QDialog
{
    Q_OBJECT

public:
    explicit Settings_window(QWidget *parent = nullptr);
    ~Settings_window();

private slots: // values are stored as long as the mainwindow is still running. So no need to copy values.
    void on_checkBox_sound_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_debug_checkStateChanged(const Qt::CheckState &arg1);

    void on_slider_volume_valueChanged(int value);

    void on_slider_R_valueChanged(int value);

    void on_slider_G_valueChanged(int value);

    void on_slider_B_valueChanged(int value);

    void on_slider_A_valueChanged(int value);

    void on_Set_volume_clicked();

    void on_Set_R_clicked();

    void on_Set_G_clicked();

    void on_Set_B_clicked();

    void on_Set_A_clicked();

private:
    Ui::Settings_window *ui;
};
