#ifndef HTLHOMPAGE_H
#define HTLHOMPAGE_H

#include <QDialog>
#include "htleditinfopage.h"
#include "htlcheckroompage.h"
#include "htlcheckorderpage.h"
#include "htladdroompage.h"
#include "htllgnwindow.h"

namespace Ui {
    class HtlHomPage;
}

class HtlHomPage : public QDialog
{
    Q_OBJECT

public:
    explicit HtlHomPage(QWidget *parent = 0);
    ~HtlHomPage();

private:
    Ui::HtlHomPage *ui;

private slots:
    void EditHotelInfo();
    void CheckRoomInfo();  // check present rooms of this hotel
    void CheckOrderInfo();  // check present orders of this hotel
    void AddRoom();
    void Logout();
};

#endif // HTLHOMPAGE_H
