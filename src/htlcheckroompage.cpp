#include "htlcheckroompage.h"
#include "ui_htlcheckroompage.h"

HtlCheckRoomPage::HtlCheckRoomPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlCheckRoomPage)
{
    ui->setupUi(this);

    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Price"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Discount"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,60);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());

    int i = 0, j = 0;
    for(i = 0; i < roomList.size(); i++){  // search rooms belong to this hotel and show
        if(roomList[i].GetBelong2Hotel() != hotelList[currentUserRank].GetHotelName()) j++;
        else{
            model->setItem(i-j,0,new QStandardItem(roomList[i].GetRoomId()));
            model->setItem(i-j,1,new QStandardItem(roomList[i].GetRoomType()));
            model->setItem(i-j,2,new QStandardItem(QString("%1").arg(roomList[i].GetOriginalRoomPrice())));
            model->setItem(i-j,3,new QStandardItem(QString("%1").arg(roomList[i].GetRoomDiscount())));
            model->setItem(i-j,4,new QStandardItem(roomList[i].GetRoomDescription()));
        }
    }

}

HtlCheckRoomPage::~HtlCheckRoomPage()
{
    delete ui;
}

void HtlCheckRoomPage::Exit(){
    this->close();
    HtlHomPage *htlHomPage = new HtlHomPage(this);
    htlHomPage->show();
}
