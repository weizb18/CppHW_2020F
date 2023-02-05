#include "ctmhompage.h"
#include "ui_ctmhompage.h"

CtmHomPage::CtmHomPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtmHomPage)
{
    ui->setupUi(this);

    ui->d_TodayLabel->setText(today.showDate());
    connect(ui->PerInfoBtn,SIGNAL(clicked()),this,SLOT(PerInfo()));
    connect(ui->LogoutBtn,SIGNAL(clicked()),this,SLOT(Logout()));
    connect(ui->KnowHtlInfoBtn,SIGNAL(clicked()),this,SLOT(KnowHtlInfo()));
    connect(ui->SearchRoomBtn,SIGNAL(clicked()),this,SLOT(SearchAvailableRoom()));
    connect(ui->CommentSortBtn,SIGNAL(clicked()),this,SLOT(CommentSort()));
    connect(ui->PriceSortBtn,SIGNAL(clicked()),this,SLOT(PriceSort()));
    connect(ui->SubmitBtn,SIGNAL(clicked()),this,SLOT(SubmitOrder()));
    connect(ui->CheckMyOrderBtn,SIGNAL(clicked()),this,SLOT(CheckMyOrder()));

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    QStandardItemModel *model = new QStandardItemModel();

    ui->tableView->setModel(model);

    model->setColumnCount(7);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Hotel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Place"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Room"));  // room id
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Price"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Comment"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Description"));

    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,60);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,60);
    ui->tableView->setColumnWidth(5,100);
    ui->tableView->setColumnWidth(6,120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());

    int i, j;
    for(i = 0; i < roomList.size(); i++){
        QString hotelname = roomList[i].GetBelong2Hotel();
        QString hotelplace;
        float hotelcomment;
        for(j = 0; j < hotelList.length(); j++){
            if(hotelList[j].GetHotelName() == hotelname){
                hotelplace = hotelList[j].GetPlace();
                hotelcomment = hotelList[j].GetComment();
                break;
            }
        }
        model->setItem(i,0,new QStandardItem(hotelname));
        model->setItem(i,1,new QStandardItem(hotelplace));
        model->setItem(i,2,new QStandardItem(roomList[i].GetRoomId()));
        model->setItem(i,3,new QStandardItem(roomList[i].GetRoomType()));
        model->setItem(i,4,new QStandardItem(QString("%1").arg(roomList[i].GetPresentRoomPrice())));
        model->setItem(i,5,new QStandardItem(QString("%1").arg(hotelcomment)));
        model->setItem(i,6,new QStandardItem(roomList[i].GetRoomDescription()));
    }


}

CtmHomPage::~CtmHomPage()
{
    delete ui;
}

void CtmHomPage::PerInfo(){
    this->close();
    CtmPerInfoPage *ctmPerInfoPage = new CtmPerInfoPage(this);
    ctmPerInfoPage->show();
}

void CtmHomPage::Logout(){
    this->close();
    CtmLgnWindow *ctmLgnWindow = new CtmLgnWindow(this);
    ctmLgnWindow->show();
}

void CtmHomPage::KnowHtlInfo(){
    int i, flag;
    int row = ui->tableView->currentIndex().row();
    if(row == -1) QMessageBox::warning(this,tr("Warning"),tr("No chosen hotel!"),QMessageBox::Yes);
    else{
        QModelIndex htlnameIndex = ui->tableView->model()->index(row,0);
        for(i = 0; i < hotelList.length(); i++){
            if(hotelList[i].GetHotelName() == ui->tableView->model()->data(htlnameIndex).toString()){
                flag = i;
                break;
            }
        }
        this->close();
        CtmKnowHtlInfoPage *ctmKnowHtlInfoPage = new CtmKnowHtlInfoPage(this);
        ctmKnowHtlInfoPage->SetHtl2Show(hotelList[flag]);
        ctmKnowHtlInfoPage->show();
        ctmKnowHtlInfoPage->showContext();
    }
}

void CtmHomPage::SearchAvailableRoom(){

    availableroomList.clear();

    int i, j;
    bool correctDate;
    QStringList beginDateList = ui->BeginDateEdit->text().split("/");
    QStringList endDateList = ui->EndDateEdit->text().split("/");
    Date beginDate(beginDateList[0].toInt(),beginDateList[1].toInt(),beginDateList[2].toInt());
    Date endDate(endDateList[0].toInt(),endDateList[1].toInt(),endDateList[2].toInt());

    if(beginDate.getTotalDays() <= today.getTotalDays() || beginDate.getTotalDays() >= endDate.getTotalDays()){
        QMessageBox::warning(this,tr("Warning"),tr("wrong date"),QMessageBox::Yes);
        correctDate = false;
    }else correctDate = true;

    if(correctDate == true){
        if(ui->PlaceLineEdit->text() == NULL && ui->TypeLineEdit->text() == NULL){
            for(i = 0; i < roomList.length(); i++){
                bool conflict = false;
                for(j = 0; j < orderList.length(); j++){
                    if(roomList[i].GetBelong2Hotel() == orderList[j].GetHotelName() && roomList[i].GetRoomId() == orderList[j].GetRoomId()){
                        if(beginDate.getTotalDays() < orderList[j].GetEndDate().getTotalDays() && endDate.getTotalDays() > orderList[j].GetBeginDate().getTotalDays())
                            conflict = true;
                    }
                }
                if(conflict == false) availableroomList.append(roomList[i]);
            }
        }else if(ui->PlaceLineEdit->text() == NULL){
            for(i = 0; i < roomList.length(); i++){
                bool conflict = false;
                for(j = 0; j < orderList.length(); j++){
                    if(roomList[i].GetBelong2Hotel() == orderList[j].GetHotelName() && roomList[i].GetRoomId() == orderList[j].GetRoomId()){
                        if(beginDate.getTotalDays() < orderList[j].GetEndDate().getTotalDays() && endDate.getTotalDays() > orderList[j].GetBeginDate().getTotalDays())
                            conflict = true;
                    }
                }
                if(conflict == false && ui->TypeLineEdit->text() == roomList[i].GetRoomType())
                    availableroomList.append(roomList[i]);
            }
        }else if(ui->TypeLineEdit->text() == NULL){
            for(i = 0; i < roomList.length(); i++){
                bool conflict = false;
                for(j = 0; j < orderList.length(); j++){
                    if(roomList[i].GetBelong2Hotel() == orderList[j].GetHotelName() && roomList[i].GetRoomId() == orderList[j].GetRoomId()){
                        if(beginDate.getTotalDays() < orderList[j].GetEndDate().getTotalDays() && endDate.getTotalDays() > orderList[j].GetBeginDate().getTotalDays())
                            conflict = true;
                    }
                }
                if(conflict == false){
                    QString htlname = roomList[i].GetBelong2Hotel();
                    QString htlplace;
                    for(j = 0; j < hotelList.length(); j++){
                        if(hotelList[j].GetHotelName() == htlname){
                            htlplace = hotelList[j].GetPlace();
                            break;
                        }
                    }
                    if(ui->PlaceLineEdit->text() == htlplace) availableroomList.append(roomList[i]);
                }
            }
        }else{
            for(i = 0; i < roomList.length(); i++){
                bool conflict = false;
                for(j = 0; j < orderList.length(); j++){
                    if(roomList[i].GetBelong2Hotel() == orderList[j].GetHotelName() && roomList[i].GetRoomId() == orderList[j].GetRoomId()){
                        if(beginDate.getTotalDays() < orderList[j].GetEndDate().getTotalDays() && endDate.getTotalDays() > orderList[j].GetBeginDate().getTotalDays())
                            conflict = true;
                    }
                }
                if(conflict == false && ui->TypeLineEdit->text() == roomList[i].GetRoomType()){
                    QString htlname = roomList[i].GetBelong2Hotel();
                    QString htlplace;
                    for(j = 0; j < hotelList.length(); j++){
                        if(hotelList[j].GetHotelName() == htlname){
                            htlplace = hotelList[j].GetPlace();
                            break;
                        }
                    }
                    if(ui->PlaceLineEdit->text() == htlplace) availableroomList.append(roomList[i]);
                }
            }
        }
        this->ShowARList();
    }
}

void CtmHomPage::SwapRoom(Room &room1, Room &room2){
    Room temp;
    temp.SetBelong2Hotel(room1.GetBelong2Hotel());
    temp.SetRoomId(room1.GetRoomId());
    temp.SetRoomType(room1.GetRoomType());
    temp.SetRoomPrice(room1.GetOriginalRoomPrice());
    temp.SetRoomDescription(room1.GetRoomDescription());
    temp.SetRoomDiscount(room1.GetRoomDiscount());
    room1.SetBelong2Hotel(room2.GetBelong2Hotel());
    room1.SetRoomId(room2.GetRoomId());
    room1.SetRoomType(room2.GetRoomType());
    room1.SetRoomPrice(room2.GetOriginalRoomPrice());
    room1.SetRoomDescription(room2.GetRoomDescription());
    room1.SetRoomDiscount(room2.GetRoomDiscount());
    room2.SetBelong2Hotel(temp.GetBelong2Hotel());
    room2.SetRoomId(temp.GetRoomId());
    room2.SetRoomType(temp.GetRoomType());
    room2.SetRoomPrice(temp.GetOriginalRoomPrice());
    room2.SetRoomDescription(temp.GetRoomDescription());
    room2.SetRoomDiscount(temp.GetRoomDiscount());
}

void CtmHomPage::ShowARList(){  // show available room list
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(7);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Hotel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Place"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Room"));  // room id
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Price"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Comment"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Description"));
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,60);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,60);
    ui->tableView->setColumnWidth(5,100);
    ui->tableView->setColumnWidth(6,120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    model->removeRows(0,model->rowCount());
    int i, j;
    for(i = 0; i < availableroomList.size(); i++){
        QString hotelname = availableroomList[i].GetBelong2Hotel();
        QString hotelplace;
        float hotelcomment;
        for(j = 0; j < hotelList.length(); j++){
            if(hotelList[j].GetHotelName() == hotelname){
                hotelplace = hotelList[j].GetPlace();
                hotelcomment = hotelList[j].GetComment();
                break;
            }
        }
        model->setItem(i,0,new QStandardItem(hotelname));
        model->setItem(i,1,new QStandardItem(hotelplace));
        model->setItem(i,2,new QStandardItem(availableroomList[i].GetRoomId()));
        model->setItem(i,3,new QStandardItem(availableroomList[i].GetRoomType()));
        model->setItem(i,4,new QStandardItem(QString("%1").arg(availableroomList[i].GetPresentRoomPrice())));
        model->setItem(i,5,new QStandardItem(QString("%1").arg(hotelcomment)));
        model->setItem(i,6,new QStandardItem(availableroomList[i].GetRoomDescription()));
    }
}

void CtmHomPage::CommentSort(){  // sort the available room list according to comment
    if(availableroomList.length() == 0)
        QMessageBox::warning(this,tr("Warning"),tr("No availableroom! Please click on 'Search' button firstly!"),QMessageBox::Yes);
    else{
        int i, j, k;
        for(i = 0; i < availableroomList.length() - 1; i++){    // bubble sort
            for(j = 0; j < availableroomList.length() - 1 - i; j++){
                QString htlname1 = availableroomList[j].GetBelong2Hotel();
                float htlcomment1;
                QString htlname2 = availableroomList[j+1].GetBelong2Hotel();
                float htlcomment2;
                for(k = 0; k < hotelList.length(); k++){
                    if(hotelList[k].GetHotelName() == htlname1){
                        htlcomment1 = hotelList[k].GetComment();
                        break;
                    }
                }
                for(k = 0; k < hotelList.length(); k++){
                    if(hotelList[k].GetHotelName() == htlname2){
                        htlcomment2 = hotelList[k].GetComment();
                        break;
                    }
                }
                if(htlcomment1 < htlcomment2) this->SwapRoom(availableroomList[j],availableroomList[j+1]);
            }
        }
        this->ShowARList();
    }
}

void CtmHomPage::PriceSort(){  // sort the available room list according to price
    if(availableroomList.length() == 0)
        QMessageBox::warning(this,tr("Warning"),tr("No availableroom! Please click on 'Search' button firstly!"),QMessageBox::Yes);
    else{
        int i, j;
        for(i = 0; i < availableroomList.length() - 1; i++)    //bubble sort
            for(j = 0; j < availableroomList.length() - 1 - i; j++)
                if(availableroomList[j].GetPresentRoomPrice() > availableroomList[j+1].GetPresentRoomPrice())
                    this->SwapRoom(availableroomList[j],availableroomList[j+1]);
        this->ShowARList();
    }
}

void CtmHomPage::SubmitOrder(){
    if(availableroomList.length() == 0)
        QMessageBox::warning(this,tr("Warning"),tr("No availableroom! Please click on 'Search' button firstly!"),QMessageBox::Yes);
    else{
        int i;
        int row = ui->tableView->currentIndex().row();
        if(row == -1) QMessageBox::warning(this,tr("Warning"),tr("No chosen room!"),QMessageBox::Yes);
        else{
            QModelIndex htlnameIndex = ui->tableView->model()->index(row,0);
            QModelIndex roomidIndex = ui->tableView->model()->index(row,2);
            for(i = 0; i < roomList.length(); i++){
                if(roomList[i].GetBelong2Hotel() == ui->tableView->model()->data(htlnameIndex).toString()
                   && roomList[i].GetRoomId() == ui->tableView->model()->data(roomidIndex).toString()){
                    QStringList beginDateList = ui->BeginDateEdit->text().split("/");
                    QStringList endDateList = ui->EndDateEdit->text().split("/");
                    Date beginDate(beginDateList[0].toInt(),beginDateList[1].toInt(),beginDateList[2].toInt());
                    Date endDate(endDateList[0].toInt(),endDateList[1].toInt(),endDateList[2].toInt());
                    float totalmoney = (endDate.getTotalDays()-beginDate.getTotalDays())*roomList[i].GetPresentRoomPrice();
                    if(customerList[currentUserRank].GetBalance() < totalmoney){
                        QMessageBox::warning(this,tr("Warning"),tr("Please charge firstly."),QMessageBox::Yes);
                    }else{
                    /*    QString context;
                        context = "You have paid" + QString("%1").arg(totalmoney);  */
                        // the parameters of "about" must be const.
                        QMessageBox::about(this,tr("About"),tr("You have paid for fees."));
                        float originalbalance = customerList[currentUserRank].GetBalance();  // pay money
                        customerList[currentUserRank].SetBalance(originalbalance-totalmoney);
                        Order newOrder;  // create a new order
                        newOrder.SetHotelName(ui->tableView->model()->data(htlnameIndex).toString());
                        newOrder.SetRoomId(ui->tableView->model()->data(roomidIndex).toString());
                        newOrder.SetRoomType(roomList[i].GetRoomType());
                        newOrder.SetCustomerId(customerList[currentUserRank].GetUsername());
                        newOrder.SetBeginDate(beginDate);
                        newOrder.SetEndDate(endDate);
                        newOrder.SetTimeSpan(endDate.getTotalDays()-beginDate.getTotalDays());
                        newOrder.SetTotalMoney(totalmoney);
                        newOrder.SetCommented(false);
                        newOrder.SetRefund(false);
                        orderList.append(newOrder);
                        break;
                    }
                }
            }
        }
        this->SearchAvailableRoom();
    }
}

void CtmHomPage::CheckMyOrder(){
    this->close();
    CtmCheckOrderPage *ctmCheckOrderPage = new CtmCheckOrderPage(this);
    ctmCheckOrderPage->show();
}
