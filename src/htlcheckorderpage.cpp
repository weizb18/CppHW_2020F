#include "htlcheckorderpage.h"
#include "ui_htlcheckorderpage.h"

HtlCheckOrderPage::HtlCheckOrderPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlCheckOrderPage)
{
    ui->setupUi(this);

    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));

    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(7);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Customer"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("BeginDate"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EndDate"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Earn"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("isCommented"));
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,100);
    ui->tableView->setColumnWidth(5,60);
    ui->tableView->setColumnWidth(6,120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());

    int i = 0, j = 0;
    for(i = 0; i < orderList.length(); i++){  // search orders belong to this hotel from orderList and show
        if(orderList[i].GetHotelName() != hotelList[currentUserRank].GetHotelName()) j++;
        else{
            QString iscommented;
            if(orderList[i].GetCommented() == true) iscommented = "yes";
            else iscommented = "no";
            model->setItem(i-j,0,new QStandardItem(orderList[i].GetCustomerId()));
            model->setItem(i-j,1,new QStandardItem(orderList[i].GetRoomId()));
            model->setItem(i-j,2,new QStandardItem(orderList[i].GetRoomType()));
            model->setItem(i-j,3,new QStandardItem(orderList[i].GetBeginDate().showDate()));
            model->setItem(i-j,4,new QStandardItem(orderList[i].GetEndDate().showDate()));
            model->setItem(i-j,5,new QStandardItem(QString("%1").arg(orderList[i].GetTotalMoney())));
            model->setItem(i-j,6,new QStandardItem(iscommented));
        }
    }
}

HtlCheckOrderPage::~HtlCheckOrderPage()
{
    delete ui;
}

void HtlCheckOrderPage::Exit(){
    this->close();
    HtlHomPage *htlHomPage = new HtlHomPage(this);
    htlHomPage->show();
}
