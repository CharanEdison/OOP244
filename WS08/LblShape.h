// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
namespace sdds {
    class LblShape: public Shape
    {
        char* m_label = nullptr;
    protected:
        const char* label()const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape&)=delete;
        void operator=(const LblShape&) = delete;
        void getSpecs(std::istream& is_);
    };
}
#endif