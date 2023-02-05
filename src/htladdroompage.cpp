#include "htladdroompage.h"
#include "ui_htladdroompage.h"

HtlAddRoomPage::HtlAddRoomPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlAddRoomPage)
{
    ui->setupUi(this);

    connect(ui->ReadFileBtn,SIGNAL(clicked()),this,SLOT(ReadFile()));
    connect(ui->ConfirmBtn,SIGNAL(clicked()),this,SLOT(Confirm()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

HtlAddRoomPage::~HtlAddRoomPage()
{
    delete ui;
}

void HtlAddRoomPage::ReadFile(){  // batch input roomid from "rooms.txt"
    QString path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(path.isEmpty() == false){
        QFile file(path);
        bool isok = file.open(QIODevice::ReadOnly);
        if(isok){
            QByteArray array = file.readAll();
            ui->IdLineEdit->setText(array);
        }
        file.close();
    }
}

void HtlAddRoomPage::Confirm(){
    bool conflict = false;
    QStringList roomidList = ui->IdLineEdit->text().split(",");  // for rooms only have different id, allow to input some ids at 1 time, separated by ','
    for(int i = 0; i < roomidList.length(); i++){
        for(int j = 0; j < roomList.length(); j++){
            if(roomidList[i] == roomList[j].GetRoomId() && hotelList[currentUserRank].GetHotelName() == roomList[j].GetBelong2Hotel()){  // the room is existed
                QMessageBox::warning(this,tr("Warning"),tr("roomId conflicts."),QMessageBox::Yes);
                conflict = true;
                break;
            }
        }
    }
    if(conflict == false){  // the room isn't existed
        for(int i = 0; i < roomidList.length(); i++){
            Room newRoom;  // create a new room
            newRoom.SetBelong2Hotel(hotelList[currentUserRank].GetHotelName());
            newRoom.SetRoomId(roomidList[i]);
            newRoom.SetRoomType(ui->TypeLineEdit->text());
            newRoom.SetRoomDescription(ui->DescriptionLineEdit->text());
            newRoom.SetRoomPrice(ui->PriceLineEdit->text().toFloat());
            newRoom.SetRoomDiscount(ui->DiscountLlineEdit->text().toFloat());
            roomList.append(newRoom);
        }
    }
/*
    for(int i = 0; i < roomList.length(); i++)
        qDebug() << roomList[i].GetRoomId() << endl;

    errors: cannot open output file debug\THotel.exe:Permission denied
            collect2: ld returned 1 exit status

          maybe because undefine the function GetRoomId() or the function GetHotelName()
*/
    this->close();
    HtlHomPage *htlHomPage = new HtlHomPage(this);
    htlHomPage->show();
}

void HtlAddRoomPage::Exit(){
    this->close();
    HtlHomPage *htlHomPage = new HtlHomPage(this);
    htlHomPage->show();
}
