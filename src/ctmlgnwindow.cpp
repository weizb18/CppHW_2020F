#include "ctmlgnwindow.h"
#include "ui_ctmlgnwindow.h"
#include "mainwindow.h"

CtmLgnWindow::CtmLgnWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtmLgnWindow)
{
    ui->setupUi(this);

    connect(ui->LoginBtn,SIGNAL(clicked()),this,SLOT(LogIn()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

CtmLgnWindow::~CtmLgnWindow()
{
    delete ui;
}

void CtmLgnWindow::LogIn(){
    bool ExistedCtm = false;
    for(int i = 0; i < customerList.length(); i++){
        if(ui->UsernameLineEdit->text() == customerList[i].GetUsername() && ui->PasswordLineEdit->text() == customerList[i].GetPassword()){
            ExistedCtm = true;
            break;
        }
    }
    if(ExistedCtm == false){
        QMessageBox::warning(this,tr("Warning"),tr("Username or password is wrong!"),QMessageBox::Yes);
        ui->UsernameLineEdit->clear();
        ui->PasswordLineEdit->clear();
        ui->UsernameLineEdit->setFocus();
    }else{
        for(int i = 0; i < customerList.length(); i++){
            if(customerList[i].GetUsername() == ui->UsernameLineEdit->text()){
                currentUserType = 1;
                currentUserRank = i;
                break;
            }
        }
        this->close();
        CtmHomPage *customerHomePage = new CtmHomPage(this);
        customerHomePage->show();
    }
}

void CtmLgnWindow::Exit(){
    ui->UsernameLineEdit->clear();
    ui->PasswordLineEdit->clear();
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
