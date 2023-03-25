// Workshop 6
// Version: 1.0
// Date: 2021/07/8
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_

namespace sdds {

    void strCpy(char* des, const char* src);

    void strnCpy(char* des, const char* src, int len);

    int strCmp(const char* s1, const char* s2);

    int strnCmp(const char* s1, const char* s2, int len);

    int strLen(const char* s);

    const char* strStr(const char* str1, const char* str2);
    
    void strCat(char* des, const char* src);
}
#endif

