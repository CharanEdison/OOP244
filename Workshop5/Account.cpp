// Workshop 5
// Version: 1.0
// Date: 2021/06/27
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }


    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance ) {
        setEmpty();
        if (number < 10000 || number > 99999 || balance <= 0) {}
        else {
            m_number = number;
            m_balance = balance;
        }
    }


    std::ostream& Account::display() const{
        if (!*this) {
            if (~*this) {
                cout << "  NEW  |         0.00 ";
            } else {
                cout << "  BAD  |    ACCOUNT   ";
            }
        } else {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        return cout;
    }


    bool Account::isInvalid()
    {
        return m_number < 0 || m_balance < 0.0;
    }

    Account::operator bool() const
    {
        if (m_number >= 10000) {
            return m_number <= 99999 && m_balance >= 0;
        } else {
            return false;
        }
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator ~() const
    {
        return m_number == 0;
    }

    Account& Account::operator =(int number)
    {
        if (!isInvalid()) {
            if (m_number == 0 && m_balance == 0.0) {
                setEmpty();
                if (number >= 10000 && number <= 99999) {
                    m_number = number;
                }
            }
        }
        return *this;
    }


    Account& Account::operator =(Account& acc)
    {
        if(!isInvalid() && this->m_number == 0 && this->m_balance == 0.0 &&  acc.m_number >= 10000 && acc.m_number <= 99999)
        {
            this->m_number = acc.m_number;
            acc.m_number = 0;
            this->m_balance = acc.m_balance;
            acc.m_balance = 0;
        }
        return *this;
    }

    Account& Account::operator +=(double val)
    {
        if (!isInvalid() && val >= 0)
            m_balance += val;
        return *this;
    }

    Account& Account::operator -=(double val)
    {
        if(!isInvalid() && val >=0 && m_balance >= val)
        {
            m_balance -= val;
        }
        return *this;
    }

    Account& Account::operator <<(Account& acc)
    {
        if (this->isInvalid() || acc.isInvalid() || this->m_number == acc.m_number)
            return *this;
        m_balance += acc.m_balance;
        acc.m_balance = 0;
        return *this;
    }


    Account& Account::operator >>(Account& acc)
    {
        if(!this->isInvalid() && !acc.isInvalid() && this->m_number != acc.m_number)
        {
            acc.m_balance += m_balance;
            m_balance = 0;
        }
        return *this;
    }

    double operator +(const Account& A, const Account& B)
    {
        if (~A || ~B)
            return 0;
        return double(A) + double(B);
    }

    double operator +=(double& val, const Account& acc)
    {
        if(!~acc)
        {
            val = (val + double(acc));
            return val;
        }
        return val;
    }
}
