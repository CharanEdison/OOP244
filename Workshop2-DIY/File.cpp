// Workshop 2
// Version: 2
// Date: 2021/06/06
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "File.h"

namespace sdds 
{
    FILE* fptr;


    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }


    int noOfRecords()
    {
        int no_of_Recs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            no_of_Recs += (ch == '\n');
        }
        rewind(fptr);
        return no_of_Recs;
    }


    void closeFile()
    {
        if (fptr) fclose(fptr);
    }


    bool read(int& population) 
    {
        if (fscanf(fptr, "%d\n", &population) == 1)
        {
            return true;
        }
        else
        {
            std::cout << "Read Failed" << std::endl;
            return false;
        }
    }


    bool read(char* post_Code)
    {
        if (fscanf(fptr, "%[^,],", post_Code) == 1)
        {
            
            return true;
        }
        else
        {
            std::cout << "Read Failed" << std::endl;
            return false;
        }

    }

}