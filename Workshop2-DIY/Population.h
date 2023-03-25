// Workshop 2
// Version: 2
// Date: 2021/06/06
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{

	struct Population
	{
		char* postCode;
		int population;
	};

	bool load(Population& record);
	bool load(const char file_Name[]);
	void sort();
	void display();
	void deallocateMemory();
}
#endif 