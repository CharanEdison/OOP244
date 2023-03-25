// Workshop 7
// Version: 1.0
// Date: 2021/07/15
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#include<iostream>
#include<iomanip>
#include "cstring.h"
#include "MotorVehicle.h"
#include "Truck.h"
using namespace std;

namespace sdds
{
    Truck::Truck(const char* plate, int year, double capacity, const char* address):MotorVehicle(plate,year)
    {
        this->m_cargo_maxi_capacity = capacity;

        this->m_Current_cargo_load_capacity = 0;

        this->moveTo(address);
    }

    bool Truck::addCargo(double cargo)
    {
        if (this->m_Current_cargo_load_capacity >= this->m_cargo_maxi_capacity)
            return false;

        if (this->m_Current_cargo_load_capacity + cargo > this->m_cargo_maxi_capacity)

            this->m_Current_cargo_load_capacity = this->m_cargo_maxi_capacity;

        else this->m_Current_cargo_load_capacity += cargo;

        return true;
    }

    bool Truck::unloadCargo()
    {
        bool unload = this->m_Current_cargo_load_capacity > 0;

        this->m_Current_cargo_load_capacity = 0;

        return unload;
    }

    std::ostream& Truck::write(std::ostream& out)const
    {
        MotorVehicle::write(out);
        out << " | ";
        out << this->m_Current_cargo_load_capacity << "/" << this->m_cargo_maxi_capacity;
        return out;
    }

    std::istream& Truck::read(std::istream& in)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> this->m_cargo_maxi_capacity;
        cout << "Cargo: ";
        in >> this->m_Current_cargo_load_capacity;

        return in;
    }

    std::istream& operator>>(std::istream& in, Truck& T)
    {
        return T.read(in);
    }

    std::ostream& operator<<(std::ostream& out, const Truck& T)
    {
        return T.write(out);
    }

}
