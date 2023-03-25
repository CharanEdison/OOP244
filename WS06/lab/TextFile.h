// Workshop 6
// Version: 1.0
// Date: 2021/07/8
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.


#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds
{
    class Text;
    class Line
    {
        char* m_value{ nullptr };
        operator const char* () const;
        Line() {}
        Line& operator=(const char*);
        ~Line();
        friend class TextFile;
        // copy and copy assignment prevention goes here
    };

    class TextFile
    {
        Line* m_textLines;
        char* m_filename;
        unsigned m_noOfLines;
        unsigned m_pageSize;
        void setFilename(const char* src, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName) const;

    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& o_str) const;
        std::istream& getFile(std::istream& i_str);
        operator bool() const;
        unsigned lines() const;
        const char* name() const;
        const char* operator[](unsigned index) const;
    };
    std::ostream& operator<<(std::ostream& o_str, const TextFile& text);
    std::istream& operator>>(std::istream& i_str, TextFile& text);

}
#endif