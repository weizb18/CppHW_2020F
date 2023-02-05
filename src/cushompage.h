#ifndef CUSHOMPAGE_H
#define CUSHOMPAGE_H

#include <QDialog>

namespace Ui {
    class CusHomPage;
}

class CusHomPage : public QDialog
{
    Q_OBJECT

public:
    explicit CusHomPage(QWidget *parent = 0);
    ~CusHomPage();

private:
    Ui::CusHomPage *ui;
};

#endif // CUSHOMPAGE_H
