// Workshop 4
// Version: 1.0
// Date: 2021/06/18
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Canister.h"
#include "cstring.h"
using namespace std;
#define PI 3.14159265
namespace sdds
{
    void Canister::setToDefault()
    {
        m_contentName = nullptr; m_diameter = 10.0; m_height = 13.0; m_contentVolume = 0.0; m_usable = true;
    }


    bool Canister::isEmpty() const
    {
        bool result;
        result = false;
        if (0.00001 > m_contentVolume) {
            result = true;
            return result;

        } else { return result; }
    }


    bool Canister::hasSameContent(const Canister& C) const
    {
        bool result;
        result = false;
        if (C.m_contentName != nullptr)
        {
            if (strCmp(m_contentName, C.m_contentName) == 0 && m_contentName != nullptr) { result = true; }
        }
        return result;

    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char* contentName)
    {
        setToDefault();

        setName(contentName);
    }


    Canister::Canister(double height, double diameter, const char* contentName)
    {
        setToDefault();

        if (height > 40.0 || height < 10.0 || diameter > 30.0 || diameter < 10) { m_usable = false; }
        else {
            m_height = height; m_diameter = diameter; m_contentVolume = 0.0;

            setName(contentName);
        }

    }

    Canister& Canister::pour(double quantity)
    {
        if (true == m_usable) {
            if (quantity > 0 && (quantity + volume() <= capacity()))
                m_contentVolume += quantity;
            else
                m_usable = false;
        } else {
            m_usable = false;
        }
        return *this;
    }

    void Canister::setName(const char* Cstr)
    {
        if (nullptr == Cstr) {
            return;
        } else {
            if (!m_usable) { return; }
        }
        delete[] m_contentName;
        m_contentName = new char[strLen(Cstr) + 1];

        strCpy(m_contentName, Cstr);
    }

    Canister::~Canister()
    {
        delete[] m_contentName;
    }

    Canister& Canister::setContent(const char* contentName)
    {

        if (contentName == nullptr) { m_usable = false; }
        else {
            if (isEmpty()) setName(contentName);
            else {
                if (strCmp(m_contentName, contentName) != 0)
                    m_usable = false;
            }
        }
        return *this;

    }


    Canister& Canister::pour(Canister& C)
    {
        setContent(C.m_contentName);

        if (C.volume() > capacity() - volume()) {
            C.m_contentVolume -= (capacity() - volume());

            m_contentVolume = capacity();
        } else {
            pour(C.m_contentVolume);

            C.m_contentVolume = 0.0;
        }
        return *this;
    }


    double Canister::volume() const
    {
        return m_contentVolume;
    }

    double Canister::capacity() const
    {
        double _capacity;
        _capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);

        return _capacity;
    }


    void Canister::clear()
    {
        delete[] m_contentName; m_contentName = nullptr; m_contentVolume = 0.0; m_usable = true;
    }

    std::ostream& Canister::display() const
    {
        cout.setf(ios::fixed);

        cout.precision(1);

        cout.width(7);

        cout << capacity();

        cout << "cc (";

        cout << m_height;

        cout << "x";

        cout << m_diameter;

        cout << ") Canister";

        if (m_usable) {
            if (m_contentName == nullptr) return cout;
            cout.setf(ios::fixed);

            cout << " of ";

            cout.precision(1);

            cout.width(7);

            cout << volume();

            cout << "cc   ";

            cout << m_contentName;
        } else cout << " of Unusable content, discard!";

        return cout;

    }

}