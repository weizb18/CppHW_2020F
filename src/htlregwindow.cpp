#include "htlregwindow.h"
#include "ui_htlregwindow.h"
#include "mainwindow.h"

HtlRegWindow::HtlRegWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HtlRegWindow)
{
    ui->setupUi(this);

    connect(ui->RegisterBtn,SIGNAL(clicked()),this,SLOT(Register()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

HtlRegWindow::~HtlRegWindow()
{
    delete ui;
}

void HtlRegWindow::Register(){
    if(ui->PasswordLineEdit->text() != ui->ConfirmLineEdit->text()){
        QMessageBox::warning(this,tr("Warning"),tr("You have input two different passwords!"),QMessageBox::Yes);
        ui->PasswordLineEdit->clear();
        ui->ConfirmLineEdit->clear();
        ui->PasswordLineEdit->setFocus();
    }else if(ui->UsernameLineEdit->text() == NULL){
        QMessageBox::warning(this,tr("Warning"),tr("Please input username!"),QMessageBox::Yes);
        ui->UsernameLineEdit->setFocus();
    }else if(ui->PasswordLineEdit->text() == NULL || ui->ConfirmLineEdit->text() == NULL){
        QMessageBox::warning(this,tr("Warning"),tr("Please input password!"),QMessageBox::Yes);
        ui->PasswordLineEdit->clear();
        ui->ConfirmLineEdit->clear();
        ui->PasswordLineEdit->setFocus();
    }else if(ui->PasswordLineEdit->text().length() < 6 || ui->PasswordLineEdit->text().length() > 12){
        QMessageBox::warning(this,tr("Warning"),tr("The length of password is not between 6-12 characters!"),QMessageBox::Yes);
        ui->PasswordLineEdit->clear();
        ui->ConfirmLineEdit->clear();
        ui->PasswordLineEdit->setFocus();
    }else if(ExistedHtlUsername(ui->UsernameLineEdit->text()) == true){
        QMessageBox::warning(this,tr("Warning"),tr("This username has been registered!"),QMessageBox::Yes);
        ui->UsernameLineEdit->clear();
        ui->UsernameLineEdit->setFocus();
    }else{  // create a new hotel
        Hotel newHotel;
        newHotel.SetUsername(ui->UsernameLineEdit->text());   newHotel.SetPassword(ui->PasswordLineEdit->text());
        newHotel.SetHotelName(ui->UsernameLineEdit->text());  newHotel.SetPlace(NULL);  newHotel.SetisPermitted(false);
        newHotel.SetComment(5.0);  newHotel.SetCommentNum(1); newHotel.SetTel(NULL); newHotel.SetAddr(NULL);
        unpermittedhotelList.append(newHotel);

        QMessageBox::about(this,tr("About"),tr("Please wait for the checking."));
        this->close();
        MainWindow *mainWindow = new MainWindow(this);
        mainWindow->show();
    }
}

void HtlRegWindow::Exit(){
    ui->UsernameLineEdit->clear();
    ui->PasswordLineEdit->clear();
    ui->ConfirmLineEdit->clear();
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
