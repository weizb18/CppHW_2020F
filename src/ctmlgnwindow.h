#ifndef CTMLGNWINDOW_H
#define CTMLGNWINDOW_H

#include <QDialog>
#include <QDebug>
#include "customer.h"
#include "list.h"
#include "ctmhompage.h"


namespace Ui {
    class CtmLgnWindow;
}

class CtmLgnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CtmLgnWindow(QWidget *parent = 0);
    ~CtmLgnWindow();

private:
    Ui::CtmLgnWindow *ui;

private slots:
    void LogIn();
    void Exit();

};

#endif // CTMLGNWINDOW_H
