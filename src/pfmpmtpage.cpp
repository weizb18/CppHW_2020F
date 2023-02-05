#include "pfmpmtpage.h"
#include "ui_pfmpmtpage.h"

PfmPmtPage::PfmPmtPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PfmPmtPage)
{
    ui->setupUi(this);

    connect(ui->PassBtn,SIGNAL(clicked()),this,SLOT(Pass()));
    connect(ui->ToHomPageBtn,SIGNAL(clicked()),this,SLOT(ToHomPage()));

    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(1);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Username"));
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());
    int i;
    for(i = 0; i < unpermittedhotelList.length(); i++)
        model->setItem(i,0,new QStandardItem(unpermittedhotelList[i].GetUsername()));
}

PfmPmtPage::~PfmPmtPage()
{
    delete ui;
}

void PfmPmtPage::Pass(){
    int row = ui->tableView->currentIndex().row();
    if(row == -1) QMessageBox::warning(this,tr("Warning"),tr("No chosen hotel!"),QMessageBox::Yes);
    else{
        QModelIndex htlusernameIndex = ui->tableView->model()->index(row,0);
        for(int i = 0; i < unpermittedhotelList.length(); i++){
            if(ui->tableView->model()->data(htlusernameIndex).toString() == unpermittedhotelList[i].GetUsername()){
                Hotel newhtl;  // create a new hotel and add into hotelList
                newhtl.SetUsername(unpermittedhotelList[i].GetUsername());  newhtl.SetPassword(unpermittedhotelList[i].GetPassword());
                newhtl.SetComment(5.0);  newhtl.SetCommentNum(1);  newhtl.SetHotelName(unpermittedhotelList[i].GetUsername());
                newhtl.SetisPermitted(true); newhtl.SetPlace("hasn't edited"); newhtl.SetTel("hasn't edited"); newhtl.SetAddr("hasn't edited");
                hotelList.append(newhtl);
                unpermittedhotelList.removeAt(i);
                break;
            }
        }
    }
}

void PfmPmtPage::ToHomPage(){
    this->close();
    PfmHomPage *pfmHomPage = new PfmHomPage(this);
    pfmHomPage->show();
}

