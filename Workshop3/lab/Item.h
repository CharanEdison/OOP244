// Workshop 3
// Version: 1.0
// Date: 2021/06/11
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.


#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds
{
	class Item
	{

		private:
			char m_itemName[21];
		bool m_taxed;
		double m_price;
		void setName(const char *name);

		public:
			void setEmpty();
		double price() const;
		double tax() const;
		void set(const char *name, double price, bool taxed);
		bool isValid() const;
		void display() const;
	};
}

#endif