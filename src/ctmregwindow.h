#ifndef CTMREGWINDOW_H
#define CTMREGWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "customer.h"
#include "list.h"
#include "ctmhompage.h"

namespace Ui {
    class CtmRegWindow;
}

class CtmRegWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CtmRegWindow(QWidget *parent = 0);
    ~CtmRegWindow();

private:
    Ui::CtmRegWindow *ui;

private slots:
    void Register();
    void Exit();

};

#endif // CTMREGWINDOW_H
