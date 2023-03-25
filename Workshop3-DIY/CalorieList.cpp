// Workshop 3
// Version: 2.0
// Date: 2021/06/13
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds
{
    int CalorieList::totalCalorie() const
    {
        int ttl = 0;
        for (int c = 0; c < m_nmbrofitems; c++)
        {
            ttl += m_Items_[c].calorie();
        }
        return ttl;
    }

    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << right << totalCalorie();
            cout << " | ";
            cout.width(12);
            cout << setfill(' ');
            cout << " |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::setEmpty()
    {
        m_Items_ = nullptr;
    }

    bool CalorieList::isValid() const
    {
        bool valid = true;
        int c;
        valid =m_Items_ != nullptr;
        for (c = 0; valid == true && c < m_nmbrofitems; c++)
        {
            valid = valid && m_Items_[c].isValid();
        }
        return valid;
    }

    void CalorieList::init(int size)
    {
        if (size < 1)
        {
            m_nmbrofitems = 0;
            m_Items_added_ = 0;
        }
        else
        {
            m_nmbrofitems = size;
            m_Items_added_ = 0;
            m_Items_ = new Food[m_nmbrofitems];
            for (int c = 0; c < m_nmbrofitems; c++)
                m_Items_[c].setEmpty();
        }
    }

    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        if (m_Items_added_ < m_nmbrofitems)
        {
            m_Items_[m_Items_added_].set(item_name, calories, when);
            m_Items_added_++;
            return true;
        }
        return false;
    }

    void CalorieList::display() const
    {
        Title();
        for (int c = 0; c < m_nmbrofitems; c++)
        {
            m_Items_[c].display();
        }
        footer();
    }

    void CalorieList::deallocate()
    {
        delete[] m_Items_;
    }
}
