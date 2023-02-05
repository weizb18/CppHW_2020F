#ifndef HTLADDROOMPAGE_H
#define HTLADDROOMPAGE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QFileDialog>
#include "room.h"
#include "htlhompage.h"
#include "list.h"

namespace Ui {
    class HtlAddRoomPage;
}

class HtlAddRoomPage : public QDialog
{
    Q_OBJECT

public:
    explicit HtlAddRoomPage(QWidget *parent = 0);
    ~HtlAddRoomPage();

private:
    Ui::HtlAddRoomPage *ui;

private slots:
    void ReadFile();  // input roomid from file "rooms.txt"
    void Confirm();
    void Exit();
};

#endif // HTLADDROOMPAGE_H
