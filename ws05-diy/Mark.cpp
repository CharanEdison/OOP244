// Workshop 5
// Version: 2.0
// Date: 2021/06/30
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    void Mark::setEmpty() {
        m_Mark_prsnt= -1;
    }

    Mark::Mark() {
        m_Mark_prsnt = 0;
    }

    Mark::Mark(int var_mark) {
        setEmpty();
        if (var_mark >= 0 && var_mark <= 100) m_Mark_prsnt = var_mark;
    }

    Mark::operator bool()const {
        bool isVaild = false;
        if (m_Mark_prsnt < 0) return isVaild;
        isVaild = true;
        return isVaild;
    }

    Mark::operator int() const {
        int crctd_mark;
        crctd_mark = m_Mark_prsnt;
        if (crctd_mark < 0 || crctd_mark > 100) {
            crctd_mark = 0;
        }
        return crctd_mark;
    }

    Mark::operator double()const {
        int m_Marks_in_GPA;
        m_Marks_in_GPA = m_Mark_prsnt;
        if ( m_Marks_in_GPA >= 50 && m_Marks_in_GPA < 60) { m_Marks_in_GPA = 1; }
        else if (m_Marks_in_GPA >= 60 && m_Marks_in_GPA < 70) { m_Marks_in_GPA = 2; }
        else if (m_Marks_in_GPA >= 70 && m_Marks_in_GPA < 80) { m_Marks_in_GPA = 3; }
        else if (m_Marks_in_GPA >= 80 && m_Marks_in_GPA <= 100) { m_Marks_in_GPA = 4; }
        else { m_Marks_in_GPA = 0; }
        return m_Marks_in_GPA;
    }

    Mark::operator char()const{
        int mark_Val = m_Mark_prsnt;
        char m_Marks_in_Grades;
        m_Marks_in_Grades = ' ';
        if (mark_Val >= 0 && mark_Val < 50) { m_Marks_in_Grades = 'F'; }
        else if (mark_Val >= 50 && mark_Val < 60) { m_Marks_in_Grades = 'D'; }
        else if (mark_Val >= 60 && mark_Val < 70) { m_Marks_in_Grades = 'C'; }
        else if (mark_Val >= 70 && mark_Val < 80) { m_Marks_in_Grades = 'B'; }
        else if (mark_Val >= 80 && mark_Val <= 100) { m_Marks_in_Grades = 'A'; }
        else { m_Marks_in_Grades = 'X'; }
        return m_Marks_in_Grades;
    }

    Mark& Mark::operator= (int var_mark) {
        m_Mark_prsnt =var_mark;
        return *this;
    }

    Mark Mark::operator+= (int var_mark) {
        if (*this && var_mark > 0) {
            m_Mark_prsnt = m_Mark_prsnt + var_mark;
        }
        return *this;
    }

    int operator+= (int& var_mark, const Mark& mark_ref);

    int operator+=(int &var_mark, const Mark &mark_ref) {
        return var_mark += int(mark_ref);
    }
}