// Workshop 7
// Version: 1.0
// Date: 2021/07/15
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#ifndef SDDS_MOTORVEHICLE
#define SDDS_MOTORVEHICLE
#include<iostream>
namespace sdds
{

    class MotorVehicle
    {
        char m_licene_plate_No_[10];

        char m_address_of_vehicle_[65];

        int m_year_of_built_;

    public:
        MotorVehicle(const char* plate, int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);

    };

    std::istream& operator>>(std::istream& in, MotorVehicle& v);
    std::ostream& operator<<(std::ostream& out, const MotorVehicle& v);
}
#endif
