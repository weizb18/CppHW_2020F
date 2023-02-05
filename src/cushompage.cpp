#include "cushompage.h"
#include "ui_cushompage.h"

CusHomPage::CusHomPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CusHomPage)
{
    ui->setupUi(this);
}

CusHomPage::~CusHomPage()
{
    delete ui;
}
