#include "htlhompage.h"
#include "ui_htlhompage.h"

HtlHomPage::HtlHomPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlHomPage)
{
    ui->setupUi(this);

    ui->d_TodayLabel->setText(today.showDate());

    connect(ui->EditInfoBtn,SIGNAL(clicked()),this,SLOT(EditHotelInfo()));
    connect(ui->CheckRoomBtn,SIGNAL(clicked()),this,SLOT(CheckRoomInfo()));
    connect(ui->CheckOrderBtn,SIGNAL(clicked()),this,SLOT(CheckOrderInfo()));
    connect(ui->AddRoomBtn,SIGNAL(clicked()),this,SLOT(AddRoom()));
    connect(ui->LogoutBtn,SIGNAL(clicked()),this,SLOT(Logout()));
}

HtlHomPage::~HtlHomPage()
{
    delete ui;
}

void HtlHomPage::EditHotelInfo(){
    this->close();
    HtlEditInfoPage *htlEditInfoPage = new HtlEditInfoPage(this);
    htlEditInfoPage->show();
}

void HtlHomPage::CheckRoomInfo(){
    this->close();
    HtlCheckRoomPage *htlCheckRoomPage = new HtlCheckRoomPage(this);
    htlCheckRoomPage->show();
}

void HtlHomPage::CheckOrderInfo(){
    this->close();
    HtlCheckOrderPage *htlCheckOrderPage = new HtlCheckOrderPage(this);
    htlCheckOrderPage->show();
}

void HtlHomPage::AddRoom(){
    this->close();
    HtlAddRoomPage *htlAddRoomPage = new HtlAddRoomPage(this);
    htlAddRoomPage->show();
}

void HtlHomPage::Logout(){
    this->close();
    HtlLgnWindow *htlLgnWindow = new HtlLgnWindow(this);
    htlLgnWindow->show();
}