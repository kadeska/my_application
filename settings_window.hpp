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

    void on_volume_actionTriggered(int action);

    void on_testbutton_clicked();

    void on_volume_valueChanged(int value);

private:
    Ui::Settings_window *ui;
};
