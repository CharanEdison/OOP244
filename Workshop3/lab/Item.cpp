// Workshop 3
// Version: 1.0
// Date: 2021/06/11
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.


#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds 
{
	
	

	void Item::setName(const char* name) 
	{
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	

	void Item::setEmpty() 
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
	}



	void Item::set(const char* name, double price, bool taxed)
	{
		if (price < 0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}



    double Item::price() const
	{
		    return m_price;
	}

	

	double Item::tax() const 
	{
		const double t_rate = 0.13;
		if (m_taxed) {
			
			return m_price * t_rate;		
		}		
		else 
		return 0.0;
		
	}

	

    bool Item::isValid() const 
	{
		if ((m_price != 0.0) && (m_itemName[0] != '\0')) {
			return true;
		}
		else
			return false;
	}

	

	void Item::display() const
	{
			if (isValid())

			{
				cout << "| ";
				cout.setf(ios::left);
				cout.width(20);
				cout.fill('.');
				cout << m_itemName;

				cout.unsetf(ios::left);
				cout << " | ";
				cout.setf(ios::fixed);
				cout.precision(2);

				cout.setf(ios::right);
				cout.width(7);
				cout.fill(' ');
				cout << m_price;

				cout.unsetf(ios::right);
				cout << " | ";

				if (!m_taxed) {
					cout << "No ";
				}
				else
					cout << "Yes";
				cout << " |" << endl;
			}

			else
				cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;

	}

	
}
