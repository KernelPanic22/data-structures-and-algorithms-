#include "CreditCardExample.h"

using namespace std;

CreditCard::CreditCard(const string no, string name, int limit, double balance)
{
    this->number = no;
    this->name = name;
    this->limit = limit;
    this->balance = balance;
}

bool CreditCard::chargeIt(double price)
{
    if (price + balance > limit)
        return false;
    balance += price;
    return true;
}

void CreditCard::makePayment(double payment)
{
    balance -= payment;
}

ostream& operator<<(ostream& out, const CreditCard& c)
{
    out << "Number = " << c.getNumber() << endl;
    out << "Name = " << c.getName() << endl;
    out << "Balance = " << c.getBalance() << endl;
    out << "Limit = " << c.getLimit() << endl;
    return out;
}