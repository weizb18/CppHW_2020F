#include "room.h"

void Room::SetBelong2Hotel(QString hotelname){
    this->belong2Hotel = hotelname;
}

void Room::SetRoomId(QString roomid){
    this->id = roomid;
}

void Room::SetRoomType(QString roomtype){
    this->type = roomtype;
}

void Room::SetRoomPrice(float roomprice){
    this->price = roomprice;
}

void Room::SetRoomDescription(QString roomdescription){
    this->description = roomdescription;
}

void Room::SetRoomDiscount(float roomdiscount){
    this->discount = roomdiscount;
}

QString Room::GetBelong2Hotel(){
    return this->belong2Hotel;
}

QString Room::GetRoomId(){
    return this->id;
}

QString Room::GetRoomType(){
    return this->type;
}

QString Room::GetRoomDescription(){
    return this->description;
}

float Room::GetOriginalRoomPrice(){
    return this->price;
}

float Room::GetRoomDiscount(){
    return this->discount;
}

float Room::GetPresentRoomPrice(){
    return this->price * this->discount;
}

bool Room::HasDiscount(){
    return this->discount < 1;
}


