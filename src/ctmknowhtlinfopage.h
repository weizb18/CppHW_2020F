#ifndef CTMKNOWHTLINFOPAGE_H
#define CTMKNOWHTLINFOPAGE_H

#include <QDialog>
#include "hotel.h"
#include "ctmhompage.h"

namespace Ui {
    class CtmKnowHtlInfoPage;
}

class CtmKnowHtlInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit CtmKnowHtlInfoPage(QWidget *parent = 0);
    ~CtmKnowHtlInfoPage();

    void SetHtl2Show(Hotel htl);  // set the hotel to show
    void showContext();  // show the info of hotel in this page


private:
    Ui::CtmKnowHtlInfoPage *ui;

    Hotel htl2show;  // hotel to show in this page

private slots:
    void Return();

};

#endif // CTMKNOWHTLINFOPAGE_H
