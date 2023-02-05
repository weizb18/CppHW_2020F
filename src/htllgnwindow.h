#ifndef HTLLGNWINDOW_H
#define HTLLGNWINDOW_H

#include <QDialog>
#include "hotel.h"
#include "list.h"
#include "htlhompage.h"

namespace Ui {
    class HtlLgnWindow;
}

class HtlLgnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HtlLgnWindow(QWidget *parent = 0);
    ~HtlLgnWindow();

private:
    Ui::HtlLgnWindow *ui;

private slots:
    void LogIn();
    void Exit();

};

#endif // HTLLGNWINDOW_H
