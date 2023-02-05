#include "list.h"

QList<Customer> customerList;
QList<Hotel> hotelList;
QList<Room> roomList;
QList<Order> orderList;
QList<Hotel> unpermittedhotelList;

int currentUserType;  //1:customer,2:hotel,3:platform
int currentUserRank;
Date today;

bool ExistedCtmUsername(QString newUsername){
    for(int i = 0; i < customerList.length(); i++)
        if(newUsername == customerList[i].GetUsername()) return true;
    return false;
}

bool ExistedHtlUsername(QString newUsername){
    for(int i = 0; i < hotelList.length(); i++)
        if(newUsername == hotelList[i].GetUsername()) return true;
    return false;
}

