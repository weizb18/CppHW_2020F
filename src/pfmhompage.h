#ifndef PFMHOMPAGE_H
#define PFMHOMPAGE_H

#include <QDialog>
#include <QDebug>
#include <QStandardItemModel>
#include "mainwindow.h"
#include "pfmpmtpage.h"
#include "date.h"
#include "list.h"

namespace Ui {
    class PfmHomPage;
}

class PfmHomPage : public QDialog
{
    Q_OBJECT

public:
    explicit PfmHomPage(QWidget *parent = 0);
    ~PfmHomPage();

private:
    Ui::PfmHomPage *ui;

private slots:
    void PermitNewHotel();  // permit hotels registered recently
    void ToNextDay();  // set the date to tomorrow
    void Logout();
};

#endif // PFMHOMPAGE_H
