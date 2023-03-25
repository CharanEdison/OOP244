// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#include <string>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {

    const char* LblShape::label()const {
        return m_label;
    }

    LblShape::LblShape()
    {

    }
    LblShape::LblShape(const char* label)
    {

        delete[] m_label;

        m_label = new char[strlen(label) + 1];

        strcpy(m_label, label);
    }

    LblShape::~LblShape()

    {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream& is_)
    {
        string label;

        getline(is_, label, ',');

        delete[] m_label;

        m_label = new char[strlen(label.c_str())+1];

        strcpy(m_label, label.c_str());
    }
}