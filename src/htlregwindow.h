#ifndef HTLREGWINDOW_H
#define HTLREGWINDOW_H

#include <QDialog>
#include "list.h"

namespace Ui {
    class HtlRegWindow;
}

class HtlRegWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HtlRegWindow(QWidget *parent = 0);
    ~HtlRegWindow();

private:
    Ui::HtlRegWindow *ui;

private slots:
    void Register();
    void Exit();

};

#endif // HTLREGWINDOW_H
