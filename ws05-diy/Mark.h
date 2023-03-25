// Workshop 5
// Version: 2.0
// Date: 2021/06/30
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.


#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_Mark_prsnt;
        void setEmpty();
    public:
        Mark();
        Mark(int var_mark);
        operator bool()const;
        operator int()const;
        operator double()const;
        operator char()const;
        Mark& operator=(int var_mark);
        Mark operator+= (int var_mark);
    };
    int operator+= (int& value, const Mark& right);
}
#endif
