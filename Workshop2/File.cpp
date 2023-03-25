// Workshop 2
// Version: 1.0
// Date: 2021/06/3
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	
	bool read(char* emplyeName) { 
		return fscanf(fptr, "%[^\n]\n", emplyeName) == 1;
	}

	bool read(int& emplyeNum) { 
		return fscanf(fptr, "%d,", &emplyeNum);
	}

	bool read(double& emplyeSalary) {
		return fscanf(fptr, "%lf,", &emplyeSalary);
	}

}

