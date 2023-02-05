#include "htllgnwindow.h"
#include "ui_htllgnwindow.h"
#include "mainwindow.h"

HtlLgnWindow::HtlLgnWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlLgnWindow)
{
    ui->setupUi(this);

    connect(ui->LoginBtn,SIGNAL(clicked()),this,SLOT(LogIn()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

HtlLgnWindow::~HtlLgnWindow()
{
    delete ui;
}

void HtlLgnWindow::LogIn(){
    bool ExistedHtl = false;
    for(int i = 0; i < hotelList.length(); i++){
        if(ui->UsernameLineEdit->text() == hotelList[i].GetUsername() && ui->PasswordLineEdit->text() == hotelList[i].GetPassword()){
            ExistedHtl = true;
            break;
        }
    }
    if(ExistedHtl == false){
        QMessageBox::warning(this,tr("Warning"),tr("Username or password is wrong!"),QMessageBox::Yes);
        ui->UsernameLineEdit->clear();
        ui->PasswordLineEdit->clear();
        ui->UsernameLineEdit->setFocus();
    }else{
        for(int i = 0; i < hotelList.length(); i++){
            if(ui->UsernameLineEdit->text() == hotelList[i].GetUsername()){
                currentUserType = 2;
                currentUserRank = i;
                break;
            }
        }
        this->close();
        HtlHomPage *hotelHomePage = new HtlHomPage(this);
        hotelHomePage->show();
    }
}

void HtlLgnWindow::Exit(){
    ui->UsernameLineEdit->clear();
    ui->PasswordLineEdit->clear();
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
