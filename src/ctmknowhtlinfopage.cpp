#include "ctmknowhtlinfopage.h"
#include "ui_ctmknowhtlinfopage.h"

CtmKnowHtlInfoPage::CtmKnowHtlInfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtmKnowHtlInfoPage)
{
    ui->setupUi(this);

    connect(ui->ReturnBtn,SIGNAL(clicked()),this,SLOT(Return()));
}

CtmKnowHtlInfoPage::~CtmKnowHtlInfoPage()
{
    delete ui;
}

void CtmKnowHtlInfoPage::SetHtl2Show(Hotel htl){
    this->htl2show.SetHotelName(htl.GetHotelName());
    this->htl2show.SetPlace(htl.GetPlace());
    this->htl2show.SetTel(htl.GetTel());
    this->htl2show.SetAddr(htl.GetAddr());
    this->htl2show.SetisPermitted(htl.GetIsPermitted());
    this->htl2show.SetComment(htl.GetComment());
    this->htl2show.SetCommentNum(htl.GetCommentNum());
}

void CtmKnowHtlInfoPage::showContext(){
    ui->d_NameLabel->setText(this->htl2show.GetHotelName());
    ui->d_PlaceLabel->setText(this->htl2show.GetPlace());
    ui->d_TelLabel->setText(this->htl2show.GetTel());
    ui->d_AddrLabel->setText(this->htl2show.GetAddr());
    ui->d_CommentLabel->setText(QString("%1").arg(this->htl2show.GetComment()));
    ui->d_CommentNumLabel->setText(QString::number(this->htl2show.GetCommentNum()));
    if(this->htl2show.GetHotelName() == "tsinghua")
        ui->frame->setStyleSheet("image: url(:/new/prefix1/hotelpics/tsinghua.jpg)");
    else if(this->htl2show.GetHotelName() == "zijing")
        ui->frame->setStyleSheet("image: url(:/new/prefix1/hotelpics/zijing.jpg)");
    else if(this->htl2show.GetHotelName() == "gugong")
        ui->frame->setStyleSheet("image: url(:/new/prefix1/hotelpics/gugong.jpg)");
    else if(this->htl2show.GetHotelName() == "qingfen")
        ui->frame->setStyleSheet("image: url(:/new/prefix1/hotelpics/qingfen.jpg)");
    else
        ui->frame->setStyleSheet("image: url(:/new/prefix1/hotelpics/nopicture.jpg)");
}

void CtmKnowHtlInfoPage::Return(){
    this->close();
    CtmHomPage *ctmHomPage = new CtmHomPage(this);
    ctmHomPage->show();
}
