#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <user.h>
class Customer : public User
{
public:
    Customer();
    void SetBalance(float setBalance);
    float GetBalance();
    void Recharge(float money);

private:
    float balance;

};

#endif // CUSTOMER_H
