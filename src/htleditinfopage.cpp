#include "htleditinfopage.h"
#include "ui_htleditinfopage.h"

HtlEditInfoPage::HtlEditInfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlEditInfoPage)
{
    ui->setupUi(this);

    ui->NameLineEdit->setText(hotelList[currentUserRank].GetHotelName());
    ui->PlaceLineEdit->setText(hotelList[currentUserRank].GetPlace());
    ui->TelLineEdit->setText(hotelList[currentUserRank].GetTel());
    ui->AddrLineEdit->setText(hotelList[currentUserRank].GetAddr());
    ui->d_CommentLabel->setText(QString("%1").arg(hotelList[currentUserRank].GetComment()));
    ui->d_CommentNumLabel->setText(QString::number(hotelList[currentUserRank].GetCommentNum()));

    connect(ui->ConfirmBtn,SIGNAL(clicked()),this,SLOT(Confirm()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

HtlEditInfoPage::~HtlEditInfoPage()
{
    delete ui;
}

void HtlEditInfoPage::Confirm(){
    int i;
    bool legal = 1;
    for(i = 0; i < hotelList.length(); i++){
        if(i == currentUserRank) continue;
        else{
            if(hotelList[i].GetHotelName() == ui->NameLineEdit->text()){
                QMessageBox::warning(this,tr("Warning"),tr("This hotel name has been registered."),QMessageBox::Yes);
                legal = 0;
                break;
            }
        }
    }
    if(legal == 1){  // the new hotel name is legal
        QString originalname = hotelList[currentUserRank].GetHotelName();
        hotelList[currentUserRank].SetHotelName(ui->NameLineEdit->text());
        hotelList[currentUserRank].SetPlace(ui->PlaceLineEdit->text());
        hotelList[currentUserRank].SetTel(ui->TelLineEdit->text());
        hotelList[currentUserRank].SetAddr(ui->AddrLineEdit->text());

        for(i = 0; i < roomList.length(); i++)
            if(roomList[i].GetBelong2Hotel() == originalname)
                roomList[i].SetBelong2Hotel(ui->NameLineEdit->text());
        for(i = 0; i < orderList.length(); i++)
            if(orderList[i].GetHotelName() == originalname)
                orderList[i].SetHotelName(ui->NameLineEdit->text());

        this->close();
        HtlHomPage *htlHomPage = new HtlHomPage(this);
        htlHomPage->show();
    }
}

void HtlEditInfoPage::Exit(){
    this->close();
    HtlHomPage *htlHomPage = new HtlHomPage(this);
    htlHomPage->show();
}
