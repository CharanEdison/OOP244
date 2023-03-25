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
#include "Food.h"
using namespace std;
namespace sdds
{
    void Food::setName(const char* name)
    {
        strCpy(m_Name_Of_Food, name);
        m_Name_Of_Food[30] = '\0';
    }

    void Food::setEmpty()
    {
        m_Name_Of_Food[0] = '\0';
        m_Calnmbr = 0;
        m_Meal_time = 0;
    }

    void Food::set(const char* item_name, int calories, int when)
    {
        if (calories < 0 || item_name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(item_name);
            m_Calnmbr = calories;
            m_Meal_time = when;
        }
    }

    void Food::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(30);
            cout << left << setfill('.') << m_Name_Of_Food;
            cout << " | ";
            cout.width(4);
            cout << left << setfill(' ');
            cout << right << m_Calnmbr;
            cout << " | ";
            cout.width(10);
            if (m_Meal_time == 1)
                cout << left << "Breakfast";
            else if (m_Meal_time == 2)
                cout << left << "Lunch";
            else if (m_Meal_time == 3)
                cout << left << "Dinner";
            else if (m_Meal_time == 4)
                cout << left << "Snack";
            cout << right << setfill(' ');
            cout << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    bool Food::isValid() const
    {
        return m_Name_Of_Food[0] != '\0' && m_Meal_time >= 1 && m_Meal_time <= 4;
    }

    int Food::calorie() const
    {
        return m_Calnmbr;
    }
}
