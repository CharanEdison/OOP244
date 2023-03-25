// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
    std::ostream& operator<<(std::ostream& os_, const Shape& S)

    {
        S.draw(os_);
        return os_;
    }

    std::istream& operator>>(std::istream& is_, Shape& S)

    {
        S.getSpecs(is_);
        return is_;

    }
}