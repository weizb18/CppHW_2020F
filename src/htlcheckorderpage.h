#ifndef HTLCHECKORDERPAGE_H
#define HTLCHECKORDERPAGE_H

#include <QDialog>
#include "list.h"
#include "htlhompage.h"

namespace Ui {
    class HtlCheckOrderPage;
}

class HtlCheckOrderPage : public QDialog
{
    Q_OBJECT

public:
    explicit HtlCheckOrderPage(QWidget *parent = 0);
    ~HtlCheckOrderPage();

private:
    Ui::HtlCheckOrderPage *ui;

private slots:
    void Exit();
};

#endif // HTLCHECKORDERPAGE_H
