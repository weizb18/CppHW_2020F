#include "hotel.h"

Hotel::Hotel()
{
}

void Hotel::SetHotelName(QString name){
    this->hotelName = name;
}

void Hotel::SetPlace(QString place){
    this->place = place;
}

void Hotel::SetTel(QString tel){
    this->tel = tel;
}

void Hotel::SetisPermitted(bool ispermitted){
    this->isPermitted = ispermitted;
}

void Hotel::SetComment(float comment){
    this->comment = comment;
}

void Hotel::SetCommentNum(int commentnum){
    this->commentNum = commentnum;
}

void Hotel::SetAddr(QString addr){
    this->addr = addr;
}

QString Hotel::GetHotelName(){
    return this->hotelName;
}

QString Hotel::GetPlace(){
    return this->place;
}

QString Hotel::GetTel(){
    return this->tel;
}

QString Hotel::GetAddr(){
    return this->addr;
}

bool Hotel::GetIsPermitted(){
    return this->isPermitted;
}

float Hotel::GetComment(){
    return this->comment;
}

int Hotel::GetCommentNum(){
    return this->commentNum;
}





