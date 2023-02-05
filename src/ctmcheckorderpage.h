#ifndef CTMCHECKORDERPAGE_H
#define CTMCHECKORDERPAGE_H

#include <QDialog>
#include "ctmhompage.h"
#include "list.h"

namespace Ui {
    class CtmCheckOrderPage;
}

class CtmCheckOrderPage : public QDialog
{
    Q_OBJECT

public:
    explicit CtmCheckOrderPage(QWidget *parent = 0);
    ~CtmCheckOrderPage();

    void ShowMyOrder();

private:
    Ui::CtmCheckOrderPage *ui;

private slots:
    void Refund();
    void Comment();
    void Exit();
};

#endif // CTMCHECKORDERPAGE_H
