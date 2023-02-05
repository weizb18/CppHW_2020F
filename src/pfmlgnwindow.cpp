#include "pfmlgnwindow.h"
#include "ui_pfmlgnwindow.h"

PfmLgnWindow::PfmLgnWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PfmLgnWindow)
{
    ui->setupUi(this);

    connect(ui->LoginBtn,SIGNAL(clicked()),this,SLOT(Login()));
    connect(ui->ExitBtn,SIGNAL(clicked()),this,SLOT(Exit()));
}

PfmLgnWindow::~PfmLgnWindow()
{
    delete ui;
}

void PfmLgnWindow::Login(){
    if(ui->UsernameLineEdit->text() == "weizibu" && ui->PasswordLineEdit->text() == "weizibu"){
        currentUserType = 3;
        currentUserRank = 0;
        this->close();
        PfmHomPage *pfmHomPage = new PfmHomPage(this);
        pfmHomPage->show();
    }else{
        QMessageBox::warning(this,tr("Warning"),tr("Username or Password is wrong."),QMessageBox::Yes);
    }
}

void PfmLgnWindow::Exit(){
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
