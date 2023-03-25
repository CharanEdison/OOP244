// Workshop 2
// Version: 1.0
// Date: 2021/06/3
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds
{

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    bool load(Employee& employee) {
        bool ok = false;
        char name[128];
        if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {
            employee.m_name = new char[strLen(name) + 1];
            strCpy(employee.m_name, name);
            return !ok;
        }
        else {
            return ok;
        }

    }
   
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees; i++) {
                load(employees[i]);
            }
            if (i != noOfEmployees) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = !ok;
                closeFile();
            }
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    void display(const Employee& employees) {
        cout << employees.m_empNo << ": " << employees.m_name << ", " <<
            employees.m_salary << endl;
    }

    void display() {
        int i;
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for (i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }
    void deallocateMemory() {
        int i;
        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
    }


}
