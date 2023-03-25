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
#include "Bill.h"

using namespace std;

namespace sdds 
{
	
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	
    bool Bill::isValid() const
	{
		bool test = true;
		if ((m_items != nullptr) && (m_title[0] != '\0'))
		{
			for (int c = 0; c < m_noOfItems; c++) {
				if (!m_items[c].isValid()) 
					test = false;
			}			 
		}
		else 
			test = true;

		return test;
		
	}

	
    

	
    double Bill::totalPrice() const 
	{
		double Var1rate = 0.0;

		for (int c = 0; c < m_noOfItems; c++) 
			Var1rate = Var1rate + m_items[c].price();
		
		return Var1rate;
	}

double Bill::totalTax() const  
	{
		double Varrate = 0.0;

		for (int c = 0; c < m_noOfItems; c++) 
			Varrate = Varrate + m_items[c].tax();
		
		return Varrate; 

	}
	
	void Bill::Title() const
	{

		cout << "+--------------------------------------+";
		cout << endl;

		if (isValid()) 
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title;
			cout << " |" << endl;

			cout.unsetf(ios::left);
		}

		else 
		cout << "| Invalid Bill                         |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	
    void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid())
		{
			cout << "|                Total Tax: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(10);
			cout << totalTax();
			cout.unsetf(ios::right);
			cout << " |" << endl;
			
			cout << "|              Total Price: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(10);
			cout << totalPrice();
			cout.unsetf(ios::right);
			cout << " |" << endl;
			
			cout << "|          Total After Tax: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(10);
			cout << totalTax() + totalPrice();
			cout.unsetf(ios::right);
			cout << " |" << endl;
		}

		else 
			cout << "| Invalid Bill                         |" << endl;
		
		cout << "+--------------------------------------+" << endl;

	}

	
	void Bill::init(const char* title, int noOfItems)
	{
		if (title[0] == '\0' || noOfItems <= 0) 
			setEmpty();
		else 
		{
			m_itemsAdded = 0;
			m_noOfItems = noOfItems;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];

			for (int c = 0; c < m_noOfItems; c++) {
				m_items[c].setEmpty();
			}
		}
	}	
    
	
	bool Bill::add(const char* item_name, double price, bool taxed){

		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded = m_itemsAdded+1;
			return true;
		}

		else 
			return false;
		
	}

	
	void Bill::display() const
	{
		Title();
		for (int c = 0; c < m_noOfItems; c++) 
		    m_items[c].display();		
		footer();
	}

	
	void Bill::deallocate() 
	{
		delete[] m_items;
		m_items = nullptr;
	}

	
	

	


}
