// Workshop 4
// Version: 1.0
// Date: 2021/06/18
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
#include "cstring.h"
namespace sdds {


    void strCpy(char* des, const char* src) {
        while (*src) {
            *des++ = *src++;
        }
        *des = 0;
    }

    void strnCpy(char* des, const char* src, int len) {
        int c = 0;
        while (c < len - 1 && src[c]) {
            des[c] = src[c];
            c++;
        }
        des[c] = src[c];
    }

    int strCmp(const char* s1, const char* s2) {
        int c = 0;
        while (s1[c] && s2[c] && s1[c] == s2[c]) {
            c++;
        }
        return s1[c] - s2[c];
    }

    int strnCmp(const char* s1, const char* s2, int len) {
        int c = 0;
        while (c < len - 1 && s1[c] && s2[c] && s1[c] == s2[c]) {
            c++;
        }
        return s1[c] - s2[c];
    }

    int strLen(const char* s) {
        int c = -1;
        while (s[++c]);
        return c;
    }

    const char* strStr(const char* str1, const char* str2) {
        const char* var1 = nullptr;
        int c=0, varlen = strLen(str2), var2len = strLen(str1);
        for (c = 0; c < var2len - varlen && strnCmp(&str1[c], str2, varlen); c++);
        if (c < var2len - varlen) var1 = &str1[c];
        return var1;
    }

    void strCat(char* des, const char* src) {
        int len = strLen(des);
        int c = 0;
        while (src[c]) {
            des[c + len] = src[c];
            c++;
        }
        des[c + len] = 0;
    }
}