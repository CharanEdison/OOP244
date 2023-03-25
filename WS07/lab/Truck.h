// Workshop 7
// Version: 1.0
// Date: 2021/07/15
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#ifndef SDDS_TRUCK
#define SDDS_TRUCK
#include<iostream>
#include "MotorVehicle.h"
namespace sdds
{
    class Truck :public MotorVehicle
    {
        double m_cargo_maxi_capacity;
        double m_Current_cargo_load_capacity;
    public:
        Truck(const char* plate,int year,double capacity,const char* address);

        bool addCargo(double cargo);

        bool unloadCargo();

        std::ostream& write(std::ostream& out)const;
        std::istream& read(std::istream& in);

    };
    std::istream& operator>>(std::istream& in, Truck& c);
    std::ostream& operator<<(std::ostream& out,const Truck& c);

}
#endif
