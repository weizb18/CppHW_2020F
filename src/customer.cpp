#include "customer.h"

Customer::Customer()
{
}

void Customer::SetBalance(float setBalance){
    this->balance = setBalance;
}

float Customer::GetBalance(){
    return this->balance;
}

void Customer::Recharge(float money){
    this->balance += money;
}


