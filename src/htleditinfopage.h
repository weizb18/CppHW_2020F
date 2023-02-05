#ifndef HTLEDITINFOPAGE_H
#define HTLEDITINFOPAGE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "htlhompage.h"
#include "list.h"

namespace Ui {
    class HtlEditInfoPage;
}

class HtlEditInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit HtlEditInfoPage(QWidget *parent = 0);
    ~HtlEditInfoPage();

private:
    Ui::HtlEditInfoPage *ui;

private slots:
    void Confirm();
    void Exit();
};

#endif // HTLEDITINFOPAGE_H
