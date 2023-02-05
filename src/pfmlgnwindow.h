#ifndef PFMLGNWINDOW_H
#define PFMLGNWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "pfmhompage.h"
#include "mainwindow.h"

namespace Ui {
    class PfmLgnWindow;
}

class PfmLgnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PfmLgnWindow(QWidget *parent = 0);
    ~PfmLgnWindow();

private:
    Ui::PfmLgnWindow *ui;

private slots:
    void Login();
    void Exit();
};

#endif // PFMLGNWINDOW_H
