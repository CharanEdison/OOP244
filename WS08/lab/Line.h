// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include"LblShape.h"

namespace sdds {

    class Line : public LblShape
            {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream&);
        void draw(std::ostream&)const;

    };
}
#endif