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

using namespace std;

namespace sdds
{

    MotorVehicle::MotorVehicle(const char* plate, int year)
    {
        this->m_year_of_built_ = year;

        strCpy(this->m_licene_plate_No_, plate);

        strCpy(this->m_address_of_vehicle_, "Factory");
    }

    void MotorVehicle::moveTo(const char* address)
    {
        cout << "|" << right << setw(8) << this->m_licene_plate_No_ << "| |" << setw(20) << right << this->m_address_of_vehicle_ << " ---> " << setw(20) << left << address << "|\n";

        strCpy(this->m_address_of_vehicle_,address);
    }


    ostream& MotorVehicle::write(std::ostream& out) const

    {
        out << "| ";
        out << this->m_year_of_built_;
        out << " | ";
        out << this->m_licene_plate_No_;
        out << " | ";
        out << this->m_address_of_vehicle_;
        return out;

    }

    istream& MotorVehicle::read(std::istream& in)

    {
        cout << "Built year: ";
        in >> this->m_year_of_built_;
        cout << "License plate: ";
        in >> this->m_licene_plate_No_;
        cout << "Current location: ";
        in >> this->m_address_of_vehicle_;
        return in;
    }

    istream& operator>>(std::istream& in, MotorVehicle& v)

    {
        return v.read(in);
    }

    ostream& operator<<(std::ostream& out, const MotorVehicle& v)
    {
        return v.write(out);
    }

}