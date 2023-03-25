// Workshop 3
// Version: 2.0
// Date: 2021/06/13
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds
{
    class Food
    {
        char m_Name_Of_Food[30];
        int m_Calnmbr;
        int m_Meal_time;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* item_name, int calories, int when);
        void display()const;
        bool isValid()const;
        int calorie()const;
    };
}

#endif 
