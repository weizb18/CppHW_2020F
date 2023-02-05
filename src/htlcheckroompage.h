#ifndef HTLCHECKROOMPAGE_H
#define HTLCHECKROOMPAGE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTextCodec>
#include <QStandardItemModel>
#include "list.h"
#include "htlhompage.h"

namespace Ui {
    class HtlCheckRoomPage;
}

class HtlCheckRoomPage : public QDialog
{
    Q_OBJECT

public:
    explicit HtlCheckRoomPage(QWidget *parent = 0);
    ~HtlCheckRoomPage();

private:
    Ui::HtlCheckRoomPage *ui;

private slots:
    void Exit();
};

#endif // HTLCHECKROOMPAGE_H
