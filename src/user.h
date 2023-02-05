#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(){}
    User(QString username, QString password);
    void SetUsername(QString username);
    void SetPassword(QString password);
    QString GetUsername();
    QString GetPassword();

protected:
    QString username;
    QString password;
};

#endif // USER_H
