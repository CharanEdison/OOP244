// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iomanip>
#include<cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds {
    Rectangle::Rectangle()
    {

    }
    Rectangle::Rectangle(const char* label, int width, int height):LblShape(label),

    m_width(width),
    m_height(height)
    {
        if (!(m_height < 3) && !(m_width < int(strlen(label) + 2))) {}
        else {
            m_width = 0;

            m_height = 0;
        }
    }

    void Rectangle::getSpecs(std::istream& is_)
    {
        LblShape::getSpecs(is_);
        is_ >> m_width;
        is_.ignore(1000, ',');
        is_ >> m_height;
        is_.ignore(1000, '\n');
    }
    void Rectangle::draw(std::ostream& os_)const
    {
        if (m_height <= 0)
            return;
        os_ << "+" << setw(m_width - 2) << setfill('-') << '-' << '+' << endl;
        os_ << "|" << setw(m_width - 2) << setfill(' ') << left << label() << '|' << endl;
        for (int c = 0; c < m_height - 3; c++)
            os_ << "|" << setw(m_width - 2) << setfill(' ') << ' ' << '|' << endl;
        os_ << "+" << setw(m_width - 2) << setfill('-') << '-' << '+';
    }

}