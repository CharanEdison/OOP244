// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include"LblShape.h"

namespace sdds {

    class Rectangle : public LblShape {

        int m_width=0,
        m_height=0;

    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void getSpecs(std::istream&);
        void draw(std::ostream&)const;
    };
}
#endif