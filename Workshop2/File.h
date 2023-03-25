// Workshop 2
// Version: 1.0
// Date: 2021/06/3
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	bool openFile(const char filename[]);

	void closeFile();

	int noOfRecords();
	
	bool read(char* emplyeName); 

	bool read(int& emplyeNum); 

	bool read(double& emplyeSalary); 


}
#endif 

