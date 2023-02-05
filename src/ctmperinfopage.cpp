#include "ctmperinfopage.h"
#include "ui_ctmperinfopage.h"

CtmPerInfoPage::CtmPerInfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtmPerInfoPage)
{
    ui->setupUi(this);
    connect(ui->ToHomPageBtn,SIGNAL(clicked()),this,SLOT(ToHomPage()));
    connect(ui->RechargeBtn,SIGNAL(clicked()),this,SLOT(Recharge()));
    ui->d_UsernameLabel->setText(customerList[currentUserRank].GetUsername());
    ui->d_BalanceLabel->setText(QString("%1").arg(customerList[currentUserRank].GetBalance()));
}

CtmPerInfoPage::~CtmPerInfoPage()
{
    delete ui;
}

void CtmPerInfoPage::ToHomPage(){
    this->close();
    CtmHomPage *ctmHomPage = new CtmHomPage(this);
    ctmHomPage->show();
}
void CtmPerInfoPage::Recharge(){
    this->close();
    bool ok;
    QString string = QInputDialog::getText(this,tr("Recharge!"),tr("Please input amount of money you want to recharge\nNo more than 1000 yuan:"),QLineEdit::Normal,"100",&ok);
    if(ok){
        float amount_of_money = string.toFloat();
        if(amount_of_money > 1000.0){
            QMessageBox::warning(this,tr("Warning"),tr("No more than 1000 yuan!"),QMessageBox::Yes);
        }else{
            customerList[currentUserRank].Recharge(amount_of_money);
            QString str1 = "Hello! ";
            QString str = str1 + customerList[currentUserRank].GetUsername();
            QMessageBox::about(this,str,tr("Succeed to recharge!\nWelcome!"));    //充值成功
        }
    }
    this->show();
}

