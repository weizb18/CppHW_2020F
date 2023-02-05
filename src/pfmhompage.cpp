#include "pfmhompage.h"
#include "ui_pfmhompage.h"

PfmHomPage::PfmHomPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PfmHomPage)
{
    ui->setupUi(this);

    ui->d_TodayLabel->setText(today.showDate());

    connect(ui->PermitNewBtn,SIGNAL(clicked()),this,SLOT(PermitNewHotel()));
    connect(ui->ToNextBtn,SIGNAL(clicked()),this,SLOT(ToNextDay()));
    connect(ui->LogoutBtn,SIGNAL(clicked()),this,SLOT(Logout()));

    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(8);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("HotelName"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Place"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("RoomNum"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Comment"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CmtNum"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Addr"));
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,120);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,120);
    ui->tableView->setColumnWidth(4,100);
    ui->tableView->setColumnWidth(5,100);
    ui->tableView->setColumnWidth(6,120);
    ui->tableView->setColumnWidth(7,150);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());
    int i, j, roomnum;
    for(i = 0; i < hotelList.length(); i++){  // show info of all hotels on platform home page
        QString htlname = hotelList[i].GetHotelName();
        roomnum = 0;
        for(j = 0; j < roomList.length(); j++){
            if(roomList[j].GetBelong2Hotel() == htlname) roomnum++;
        }
        model->setItem(i,0,new QStandardItem(hotelList[i].GetUsername()));
        model->setItem(i,1,new QStandardItem(htlname));
        model->setItem(i,2,new QStandardItem(hotelList[i].GetPlace()));
        model->setItem(i,3,new QStandardItem(QString::number(roomnum)));
        model->setItem(i,4,new QStandardItem(QString("%1").arg(hotelList[i].GetComment())));
        model->setItem(i,5,new QStandardItem(QString::number(hotelList[i].GetCommentNum())));
        model->setItem(i,6,new QStandardItem(hotelList[i].GetTel()));
        model->setItem(i,7,new QStandardItem(hotelList[i].GetAddr()));
    }
}

PfmHomPage::~PfmHomPage()
{
    delete ui;
}

void PfmHomPage::PermitNewHotel(){
    this->close();
    PfmPmtPage *pfmPmtPage = new PfmPmtPage(this);
    pfmPmtPage->show();
}

void PfmHomPage::ToNextDay(){
    today = today.AfterDate(1);
    ui->d_TodayLabel->setText(today.showDate());
}

void PfmHomPage::Logout(){
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
