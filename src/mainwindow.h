#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QButtonGroup>
#include "ctmregwindow.h"
#include "htlregwindow.h"
#include "ctmlgnwindow.h"
#include "htllgnwindow.h"
#include "pfmlgnwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    QButtonGroup *bg;    // attention: you cannot declare a control-widget here!

private:
    Ui::MainWindow *ui;

private slots:
    void RegisterBtn_clicked();
    void LogInBtn_clicked();
    void ShowCtmLogInWindow();
    void ShowCtmRegWindow();
    void ShowHtlLogInWindow();
    void ShowHtlRegWindow();
    void ShowPfmLogInWindow();
};

#endif // MAINWINDOW_H
