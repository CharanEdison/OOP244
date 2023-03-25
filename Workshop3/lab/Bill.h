// Workshop 3
// Version: 1.0
// Date: 2021/06/11
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"

namespace sdds
{
	class Bill
	{

		private:
			char m_title[37];
		Item * m_items;
		int m_noOfItems;
		int m_itemsAdded;
		double totalTax() const;
		double totalPrice() const;
		void Title() const;
		void footer() const;
		void setEmpty();
		bool isValid() const;

		public:
			void init(const char *title, int noOfItems);
		bool add(const char *item_name, double price, bool taxed);
		void display() const;
		void deallocate();
	};
}
#endif