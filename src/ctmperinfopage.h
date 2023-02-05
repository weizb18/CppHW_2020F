#ifndef CTMPERINFOPAGE_H
#define CTMPERINFOPAGE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include "customer.h"
#include "ctmhompage.h"

namespace Ui {
    class CtmPerInfoPage;
}

class CtmPerInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit CtmPerInfoPage(QWidget *parent = 0);
    ~CtmPerInfoPage();

private:
    Ui::CtmPerInfoPage *ui;

private slots:
    void ToHomPage();  // back to customer home page
    void Recharge();
};

#endif // CTMPERINFOPAGE_H
