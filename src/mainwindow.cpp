#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRadioButton>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("image: url(:/new/prefix1/hotelpics/thotel.png)");
//    QButtonGroup *bg = new QButtonGroup(this);
    ui->bg->addButton(ui->CustomerRadioBtn, 0);
    ui->bg->addButton(ui->HotelRadioBtn, 1);
    ui->bg->addButton(ui->PlatformRadioBtn, 2);
    connect(ui->RegisterBtn,SIGNAL(clicked()),this,SLOT(RegisterBtn_clicked()));
    connect(ui->LogInBtn,SIGNAL(clicked()),this,SLOT(LogInBtn_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RegisterBtn_clicked(){
    int selectedId = ui->bg->checkedId();
    switch(selectedId){
    case 0:
        this->ShowCtmRegWindow();
        break;
    case 1:
        this->ShowHtlRegWindow();
        break;
    case 2:
        QMessageBox::warning(this,tr("Warning"),tr("You cannout register platform."),QMessageBox::Yes);
        break;
    }
}

void MainWindow::LogInBtn_clicked(){
    int selectedId = ui->bg->checkedId();
    switch(selectedId){
    case 0:
        this->ShowCtmLogInWindow();
        break;
    case 1:
        this->ShowHtlLogInWindow();
        break;
    case 2:
        this->ShowPfmLogInWindow();
        break;
    }
}

void MainWindow::ShowCtmLogInWindow(){
    this->close();
    CtmLgnWindow *ctmLgnWindow = new CtmLgnWindow(this);
    ctmLgnWindow->show();
}

void MainWindow::ShowCtmRegWindow(){
    this->close();
    CtmRegWindow *ctmRegWindow = new CtmRegWindow(this);
    ctmRegWindow->show();
}

void MainWindow::ShowHtlLogInWindow(){
    this->close();
    HtlLgnWindow *htlLgnWindow = new HtlLgnWindow(this);
    htlLgnWindow->show();
}

void MainWindow::ShowHtlRegWindow(){
    this->close();
    HtlRegWindow *htlRegWindow = new HtlRegWindow(this);
    htlRegWindow->show();
}

void MainWindow::ShowPfmLogInWindow(){
    this->close();
    PfmLgnWindow *pfmLgnWindow = new PfmLgnWindow(this);
    pfmLgnWindow->show();
}

