// Workshop 5
// Version: 1.0
// Date: 2021/06/27
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
        bool isInvalid();


    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator ~() const;
        Account& operator =(int);
        Account& operator =(Account&);
        Account& operator +=(double);
        Account& operator -=(double);
        Account& operator <<(Account&);
        Account& operator >>(Account&);
    };
    double operator +(const Account&, const Account&);
    double operator +=(double&, const Account&);

}
#endif
