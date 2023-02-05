#include "order.h"

int Order::idnum = 0;

Order::Order()
{
    this->id = idnum;
    idnum++;
}

Order::~Order(){}

int Order::GetOrderId(){
    return this->id;
}

QString Order::GetHotelName(){
    return this->hotelname;
}

QString Order::GetRoomId(){
    return this->roomid;
}

QString Order::GetRoomType(){
    return this->roomtype;
}

QString Order::GetCustomerId(){
    return this->customerid;
}

float Order::GetTotalMoney(){
    return this->totalmoney;
}

int Order::GetTimeSpan(){
    return this->timespan;
}

Date Order::GetBeginDate(){
    return this->beginDate;
}

Date Order::GetEndDate(){
    return this->endDate;
}

void Order::SetOrderId(int orderid){
    this->id = orderid;
}

void Order::SetHotelName(QString hname){
    this->hotelname = hname;
}

void Order::SetRoomId(QString rid){
    this->roomid = rid;
}

void Order::SetRoomType(QString rtype){
    this->roomtype = rtype;
}

void Order::SetCustomerId(QString cid){
    this->customerid = cid;
}

void Order::SetTotalMoney(float tmoney){
    this->totalmoney = tmoney;
}

void Order::SetTimeSpan(int tspan){
    this->timespan = tspan;
}

void Order::SetTimeSpan(){
    this->timespan = this->endDate.getTotalDays() - this->beginDate.getTotalDays();
}

void Order::SetBeginDate(Date bdate){
    this->beginDate = bdate;
}

void Order::SetEndDate(Date edate){
    this->endDate = edate;
}

bool Order::GetExistence(){
    return this->existence;
}

bool Order::GetNewOrder(){
    return this->neworder;
}

bool Order::GetCommented(){
    return this->commented;
}

bool Order::GetRefund(){
    return this->refund;
}

void Order::SetExistence(bool exist){
    this->existence = exist;
}

void Order::SetNewOrder(bool norder){
    this->neworder = norder;
}

void Order::SetCommented(bool comment){
    this->commented = comment;
}

void Order::SetRefund(bool rfund){
    this->refund = rfund;
}

QStringList Order::GetOrderInfo(){
    QStringList info;
    info.append(this->GetHotelName());
    info.append(this->GetRoomId());
    info.append(this->GetRoomType());
    info.append(this->GetCustomerId());
    info.append(QString::number(this->GetTotalMoney()));
    info.append(QString::number(this->GetBeginDate().getYear()));
    info.append(QString::number(this->GetBeginDate().getMonth()));
    info.append(QString::number(this->GetBeginDate().getDay()));
    info.append(QString::number(this->GetEndDate().getYear()));
    info.append(QString::number(this->GetEndDate().getMonth()));
    info.append(QString::number(this->GetEndDate().getDay()));
    return info;
}
