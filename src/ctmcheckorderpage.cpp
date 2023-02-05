#include "ctmcheckorderpage.h"
#include "ui_ctmcheckorderpage.h"

CtmCheckOrderPage::CtmCheckOrderPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtmCheckOrderPage)
{
    ui->setupUi(this);

    ui->DateLabel->setText(today.showDate());

    connect(ui->RefundBtn,SIGNAL(clicked()),this,SLOT(Refund()));
    connect(ui->CommentBtn,SIGNAL(clicked()),this,SLOT(Comment()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
    this->ShowMyOrder();
}

CtmCheckOrderPage::~CtmCheckOrderPage()
{
    delete ui;
}

void CtmCheckOrderPage::ShowMyOrder(){  // search orders belong to current customer in the orderList
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(9);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Hotel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Place"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Room"));  // room id
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Begin"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("End"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Money"));  // show total money of this order
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Comment"));  // show whether this order has been commented
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,120);
    ui->tableView->setColumnWidth(2,60);
    ui->tableView->setColumnWidth(3,80);
    ui->tableView->setColumnWidth(4,120);
    ui->tableView->setColumnWidth(5,100);
    ui->tableView->setColumnWidth(6,100);
    ui->tableView->setColumnWidth(7,60);
    ui->tableView->setColumnWidth(8,120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());
    int i, j, jj, k = -1;
    for(i = 0; i < orderList.size(); i++){
        if(orderList[i].GetCustomerId() == customerList[currentUserRank].GetUsername()){
            k++;
            QString hotelname = orderList[i].GetHotelName();
            QString hotelplace;
            float hotelcomment;
            for(j = 0; j < hotelList.length(); j++){
                if(hotelList[j].GetHotelName() == hotelname){
                    hotelplace = hotelList[j].GetPlace();
                    hotelcomment = hotelList[j].GetComment();
                    break;
                }
            }
            QString description;
            for(jj = 0; jj < roomList.length(); jj++){
                if(roomList[jj].GetBelong2Hotel() == orderList[i].GetHotelName() && roomList[jj].GetRoomId() == orderList[i].GetRoomId()){
                    description = roomList[jj].GetRoomDescription();
                    break;
                }
            }
            bool commented = orderList[i].GetCommented();
            QString commentshow;
            if(commented == false) commentshow = "no";
            else commentshow = "yes";
            model->setItem(k,0,new QStandardItem(hotelname));
            model->setItem(k,1,new QStandardItem(hotelplace));
            model->setItem(k,2,new QStandardItem(orderList[i].GetRoomId()));
            model->setItem(k,3,new QStandardItem(orderList[i].GetRoomType()));
            model->setItem(k,4,new QStandardItem(description));
            model->setItem(k,5,new QStandardItem(orderList[i].GetBeginDate().showDate()));
            model->setItem(k,6,new QStandardItem(orderList[i].GetEndDate().showDate()));
            model->setItem(k,7,new QStandardItem(QString("%1").arg(orderList[i].GetTotalMoney())));
            model->setItem(k,8,new QStandardItem(commentshow));
        }
    }
}

void CtmCheckOrderPage::Refund(){
    int i;
    int row = -1;
    row = ui->tableView->currentIndex().row();
    if(row == -1) QMessageBox::warning(this,tr("Warning"),tr("No chosen order!"),QMessageBox::Yes);
    else{
        QModelIndex htlnameIndex = ui->tableView->model()->index(row,0);
        QModelIndex roomidIndex = ui->tableView->model()->index(row,2);
        QModelIndex begindateIndex = ui->tableView->model()->index(row,5);
        QModelIndex enddateIndex = ui->tableView->model()->index(row,6);
        QModelIndex refundIndex = ui->tableView->model()->index(row,7);
        QString htlname = ui->tableView->model()->data(htlnameIndex).toString();
        QString roomid = ui->tableView->model()->data(roomidIndex).toString();
        QString begindate = ui->tableView->model()->data(begindateIndex).toString();
        QString enddate = ui->tableView->model()->data(enddateIndex).toString();
        QString refund = ui->tableView->model()->data(refundIndex).toString();
        QStringList beginDateList = begindate.split("-");
        QStringList endDateList = enddate.split("-");
        Date beginDate(beginDateList[0].toInt(),beginDateList[1].toInt(),beginDateList[2].toInt());
        Date endDate(endDateList[0].toInt(),endDateList[1].toInt(),endDateList[2].toInt());
        if(beginDate.getTotalDays() <= today.getTotalDays())
            QMessageBox::warning(this,tr("Warning"),tr("The order has started!"),QMessageBox::Yes);
        else{  // refund and remove this order from orderList
            for(i = 0; i < orderList.length(); i++){
                if(orderList[i].GetHotelName() == htlname && orderList[i].GetRoomId() == roomid
                   && orderList[i].GetBeginDate().getTotalDays() == beginDate.getTotalDays()
                   && orderList[i].GetEndDate().getTotalDays() == endDate.getTotalDays()
                   && orderList[i].GetCustomerId() == customerList[currentUserRank].GetUsername()){
                    orderList[i].SetRefund(true);
                    float prebalance = customerList[currentUserRank].GetBalance();
                    float refundmoney = refund.toFloat();
                    customerList[currentUserRank].SetBalance(prebalance + refundmoney);
                    QMessageBox::about(this,tr("about"),tr("succeed to refund"));
                    orderList.removeAt(i);
                    break;
                }
            }
        }
    }
    this->ShowMyOrder();
}

void CtmCheckOrderPage::Comment(){
    int row = -1;
    row = ui->tableView->currentIndex().row();
    if(row == -1) QMessageBox::warning(this,tr("Warning"),tr("No chosen order!"),QMessageBox::Yes);
    else{
        QModelIndex htlnameIndex = ui->tableView->model()->index(row,0);
        QModelIndex roomidIndex = ui->tableView->model()->index(row,2);
        QModelIndex begindateIndex = ui->tableView->model()->index(row,5);
        QModelIndex enddateIndex = ui->tableView->model()->index(row,6);
        QModelIndex refundIndex = ui->tableView->model()->index(row,7);
        QString htlname = ui->tableView->model()->data(htlnameIndex).toString();
        QString roomid = ui->tableView->model()->data(roomidIndex).toString();
        QString begindate = ui->tableView->model()->data(begindateIndex).toString();
        QString enddate = ui->tableView->model()->data(enddateIndex).toString();
        QString refund = ui->tableView->model()->data(refundIndex).toString();
        QStringList beginDateList = begindate.split("-");
        QStringList endDateList = enddate.split("-");
        Date beginDate(beginDateList[0].toInt(),beginDateList[1].toInt(),beginDateList[2].toInt());
        Date endDate(endDateList[0].toInt(),endDateList[1].toInt(),endDateList[2].toInt());
        if(endDate.getTotalDays() > today.getTotalDays())
            QMessageBox::warning(this,tr("Warning"),tr("The order hasn't finished!"),QMessageBox::Yes);
        else{
            bool ok;
            QString cmtstring = QInputDialog::getText(this,tr("Comment"),tr("Please input your comment\n Integer from 1 to 5:"),QLineEdit::Normal,"5",&ok);
            if(ok){
                int i, j;
                for(i = 0; i < orderList.length(); i++){
                    if(orderList[i].GetHotelName() == htlname && orderList[i].GetRoomId() == roomid
                       && orderList[i].GetBeginDate().getTotalDays() == beginDate.getTotalDays()
                       && orderList[i].GetEndDate().getTotalDays() == endDate.getTotalDays()
                       && orderList[i].GetCustomerId() == customerList[currentUserRank].GetUsername()){

                        int score = cmtstring.toInt();
                        if(orderList[i].GetCommented() == true) QMessageBox::warning(this,tr("Warning"),tr("You have commented."),QMessageBox::Yes);
                        else if(score < 1 || score > 5) QMessageBox::warning(this,tr("Warning"),tr("comment should be 1-5"),QMessageBox::Yes);
                        else{
                            orderList[i].SetCommented(true);
                            for(j = 0; j < hotelList.length(); j++){
                                if(htlname == hotelList[j].GetHotelName()){
                                    int prenum = hotelList[j].GetCommentNum();
                                    float precmt = hotelList[j].GetComment() * hotelList[j].GetCommentNum();
                                    hotelList[j].SetCommentNum(prenum+1);
                                    hotelList[j].SetComment((precmt + score)/(prenum+1));
                                    break;
                                }
                            }
                        }

                    }
                }
            }
        }
    }
    this->ShowMyOrder();
}

void CtmCheckOrderPage::Exit(){
    this->close();
    CtmHomPage *ctmHomPage = new CtmHomPage(this);
    ctmHomPage->show();
}
