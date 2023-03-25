// Workshop 2
// Version: 1.0
// Date: 2021/06/3
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds
{
    struct Employee
    {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    
    void sort();
    
    bool load(Employee& employee);
    
    bool load();

    void display(const Employee& employees);
    
    void display();
    
    void deallocateMemory();
}
#endif

