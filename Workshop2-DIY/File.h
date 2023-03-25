// Workshop 2
// Version: 2
// Date: 2021/06/06
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.#define _CRT_SECURE_NO_WARNINGS#ifndef SDDS_FILE_H_
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	bool openFile(const char file_Name[]);
	void closeFile();
	int noOfRecords();
	bool read(int& population);
	bool read(char* post_Code);
}
#endif // !SDDS_FILE_H_