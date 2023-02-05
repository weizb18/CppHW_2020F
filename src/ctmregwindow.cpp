#include "ctmregwindow.h"
#include "ui_ctmregwindow.h"
#include "mainwindow.h"

CtmRegWindow::CtmRegWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtmRegWindow)
{
    ui->setupUi(this);

    connect(ui->RegisterBtn,SIGNAL(clicked()),this,SLOT(Register()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

CtmRegWindow::~CtmRegWindow()
{
    delete ui;
}

void CtmRegWindow::Register(){
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
    }else if(ExistedCtmUsername(ui->UsernameLineEdit->text()) == true){
        QMessageBox::warning(this,tr("Warning"),tr("This username has been registered!"),QMessageBox::Yes);
        ui->UsernameLineEdit->clear();
        ui->UsernameLineEdit->setFocus();
    }else{  // register successfully, create a new customer
        Customer newCustomer;
        newCustomer.SetUsername(ui->UsernameLineEdit->text());
        newCustomer.SetPassword(ui->PasswordLineEdit->text());
        newCustomer.SetBalance(100.0);
        customerList.append(newCustomer);
        currentUserType = 1;
        currentUserRank = customerList.length() - 1;
        this->close();
        CtmHomPage *customerHomePage = new CtmHomPage(this);
        customerHomePage->show();
    }
}

void CtmRegWindow::Exit(){
    ui->UsernameLineEdit->clear();
    ui->PasswordLineEdit->clear();
    ui->ConfirmLineEdit->clear();
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
