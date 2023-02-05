#ifndef CTMHOMPAGE_H
#define CTMHOMPAGE_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#include <QStandardItemModel>
#include "list.h"
#include "date.h"
#include "ctmperinfopage.h"
#include "ctmlgnwindow.h"
#include "ctmcheckorderpage.h"
#include "ctmknowhtlinfopage.h"

namespace Ui {
    class CtmHomPage;
}

class CtmHomPage : public QDialog
{
    Q_OBJECT

public:
    explicit CtmHomPage(QWidget *parent = 0);
    ~CtmHomPage();

    void ShowARList();  // show the available room list in the tableview
    void SwapRoom(Room &room1, Room &room2);

private:
    Ui::CtmHomPage *ui;

    QList<Room> availableroomList;

private slots:
    void PerInfo();
    void Logout();
    void KnowHtlInfo();
    void SearchAvailableRoom();
    void CommentSort();
    void PriceSort();
    void SubmitOrder();
    void CheckMyOrder();

};

#endif // CTMHOMPAGE_H
