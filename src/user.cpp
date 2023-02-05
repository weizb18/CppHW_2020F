#include "user.h"


User::User(QString username, QString password){
    this->username = username;
    this->password = password;
}

void User::SetUsername(QString username){
    this->username = username;
}

void User::SetPassword(QString password){
    this->password = password;
}

QString User::GetUsername(){
    return this->username;
}

QString User::GetPassword(){
    return this->password;
}

