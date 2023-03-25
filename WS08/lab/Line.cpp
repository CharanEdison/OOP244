// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iomanip>
#include "Line.h"

using namespace std;
namespace sdds {
    Line::Line():m_length(0)
    {

    }
    Line::Line(const char* label,
               int length) :LblShape(label),
    m_length(length)
    {

    }

    void Line::getSpecs(std::istream& is_)
    {
        LblShape::getSpecs(is_);
        is_ >> m_length;
        is_.ignore(1000, '\n');

    }
    void Line::draw(std::ostream& os)const
    {
        if (m_length <= 0 || label() == nullptr)
            return;
        os << label() << endl;

        int c;

        for (c = 0; c < m_length; c++)	os << "=";
    }
}