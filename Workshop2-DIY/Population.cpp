// Workshop 2
// Version: 2
// Date: 2021/06/06
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.#define _CRT_SECURE_NO_WARNINGSusing namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>        
#include "Population.h"
#include "File.h"  

using namespace std;
namespace sdds 
{
	int totRecord;
	Population* pop;


	bool load(Population& record)
	{
		bool load = false;
		char tempcode_[10];

		if (read(tempcode_) && read(record.population))
		{
			int tempLen_ = strlen(tempcode_) + 1;
			record.postCode = new char[tempLen_];
			strcpy(record.postCode, tempcode_);
			load = true;
		}
		return load;
	}


	bool load(const char filename[])
	{
		bool ok = false;
		
		if (openFile(filename))
		{
			totRecord = noOfRecords();
			pop = new Population[totRecord];

			for (int c = 0; c < totRecord; c++)
			{
				if (load(pop[c]) == false)
				{
					cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
					break;
				}
				else
				{
					ok = true;
				}
			}

			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << filename;
		}
		return ok;
	}


	void sort()
	{
		int c, o;
		Population temp;
		for (c = totRecord - 1; c > 0; c--)
		{
			for (o= 0; o < c; o++)
			{
				if (pop[o].population > pop[o + 1].population)
				{
					temp = pop[o];
					pop[o] = pop[o + 1];
					pop[o + 1] = temp;
				}
			}
		}
	}


	void display()
	{
		int ttlPopulation = 0;

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sort();

		for (int c= 0; c < totRecord; c++)
		{
			cout << c + 1 << "- " << pop[c].postCode << ":  " << pop[c].population << endl;
			ttlPopulation += pop[c].population;
		}

		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << ttlPopulation << endl;
	}


	void deallocateMemory()
	
    {
        for (int c = 0; c < totRecord; c++) {
            delete[] pop[c].postCode;
            pop[c].postCode = nullptr;
        }
        delete[] pop;
        pop = nullptr;
    }
}