#ifndef PFMPMTPAGE_H
#define PFMPMTPAGE_H

#include <QDialog>
#include "list.h"
#include "pfmhompage.h"

namespace Ui {
    class PfmPmtPage;
}

class PfmPmtPage : public QDialog
{
    Q_OBJECT

public:
    explicit PfmPmtPage(QWidget *parent = 0);
    ~PfmPmtPage();

private:
    Ui::PfmPmtPage *ui;

private slots:
    void Pass();  // permit new hotel
    void ToHomPage();

};

#endif // PFMPMTPAGE_H
