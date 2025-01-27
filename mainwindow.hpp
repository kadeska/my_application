#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "settings_window.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Settings_window settingswindow;
    ~MainWindow();

private slots:
    void on_actionSave_triggered();

    // This is where the openGl game window is opened.
    void on_actionGL_Window_triggered();

    void on_actionSettings_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_HPP
