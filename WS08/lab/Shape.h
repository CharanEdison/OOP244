// Workshop 8
// Version: 1.0
// Date: 2021/07/22
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include<iostream>
namespace sdds {
    class Shape
    {
    public:
        virtual void draw(std::ostream&) const = 0;
        virtual void getSpecs(std::istream&) = 0;
        virtual ~Shape(){}

    };
    std::ostream& operator<< (std::ostream& os_, const Shape& S);
    std::istream& operator>> (std::istream& is_, Shape& S);
}
#endif