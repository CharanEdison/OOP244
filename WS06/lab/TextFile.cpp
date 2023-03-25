// Workshop 6
// Version: 1.0
// Date: 2021/07/8
// Name:Charan Edison Arulraj
//Seneca Student ID:143594208
//Seneca email:cedison-arulraj@myseneca.ca
//section:ZCC
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
    Line::operator const char* () const
    {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue)
    {
        delete[] m_value;
        if (lineValue == nullptr)
        {
            m_value = new char[0];
        }
        else
        {
            m_value = new char[strLen(lineValue) + 1];
        }
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line()
    {
        delete[] m_value;
    }

    void TextFile::setFilename(const char* src, bool isCopy)
    {
        delete[] m_filename;
        if (!isCopy) {
            m_filename = new char[src == nullptr ? 0 : strLen(src) + 1];
            strCpy(m_filename, src);
        } else {
            m_filename = new char[src == nullptr ? 0 : strLen(src) + 3];
            string copy_name = "C_";
            for (int i = 0; i < (int) strLen(src); i++) {
                copy_name += src[i];
            }
            strCpy(m_filename, copy_name.c_str());
        }
    }

    void TextFile::setNoOfLines()
    {
        int c;
        c = 0;
        ifstream in;
        in.open(m_filename);
        string line;
        while (getline(in, line))
            c++;
        in.close();
        if (c != 0)
        {
            m_noOfLines = c;
        }
        else
        {
            delete[] m_filename;
            m_filename = nullptr;
            m_noOfLines = 0;
        }
    }

    void TextFile::loadText()
    {
        delete[] m_textLines;
        if (m_filename == nullptr)
            return;
        m_textLines = new Line[m_noOfLines];
        ifstream in;
        in.open(m_filename);
        if (in.is_open())
        {
            string line;
            for (int x = 0; x < (int)m_noOfLines; x++)
            {
                getline(in, line);
                m_textLines[x] = line.c_str();
            }
        }
        in.close();
    }

    void TextFile::saveAs(const char* fileName) const
    {
        if (fileName == nullptr)
            return;
        ofstream _out;
        _out.open(fileName);
        if (_out.is_open())
            for (int x = 0; x < (int)m_noOfLines; x++)
                _out << m_textLines[x] << '\n';
        _out.close();
    }

    TextFile::TextFile(unsigned int pageSize)
    {
        m_pageSize = pageSize;
        this->m_filename = nullptr;
        this->m_textLines = nullptr;
        this->m_noOfLines = 0;
    }

    TextFile::TextFile(const char* filename, unsigned int pageSize)
    {
        m_pageSize = pageSize;
        this->m_filename = nullptr;
        this->m_textLines = nullptr;
        this->m_noOfLines = 0;
        if (filename != nullptr)
        {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& _text)
    {
        m_pageSize = _text.m_pageSize;
        this->m_filename = nullptr;
        this->m_textLines = nullptr;
        this->m_noOfLines = 0;
        setFilename(_text.m_filename, true);
        _text.saveAs(m_filename);
        setNoOfLines();
        loadText();
    }

    TextFile& TextFile::operator=(const TextFile& _text)
    {
        if (this != &_text)
        {
            delete[] this->m_textLines;
            m_textLines = nullptr;
            _text.saveAs(m_filename);
            setNoOfLines();
            loadText();
            return *this;
        }
        else
        {
            return *this;


        }
    }

    TextFile::~TextFile()
    {
        delete[] this->m_filename;
        delete[] this->m_textLines;
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    std::ostream& TextFile::view(ostream& o_str) const
    {
        if (!*this) { return o_str; }
        else {
            o_str << m_filename << endl;
            o_str.width(m_filename == nullptr ? 0 : strLen(m_filename));
            o_str.fill('=');
            o_str << "" << endl;
            for (int x = 0; x < (int) m_noOfLines; x++) {
                if (!(x % m_pageSize) && x) {
                    o_str << "Hit ENTER to continue...";
                    cin.get();
                }
                o_str << m_textLines[x].m_value << endl;
            }
            return o_str;
        }
    }

    std::istream& TextFile::getFile(istream& i_str)
    {
        string y;
        i_str >> y;
        while (getchar() != '\n')
            ;
        setFilename(y.c_str());
        setNoOfLines();
        loadText();
        return i_str;
    }

    const char* TextFile::operator[](unsigned int index) const
    {
        if (m_textLines != nullptr)
        {
            return m_textLines[index % m_noOfLines];
        }
        return nullptr;
    }

    TextFile::operator bool() const
    {
        return !(!this->m_noOfLines || nullptr == this->m_textLines || nullptr == this->m_filename);
    }

    const char* TextFile::name() const
    {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& o_str, const TextFile& text)
    {
        text.view(o_str);
        return o_str;
    }

    std::istream& operator>>(std::istream& i_str, TextFile& text)
    {
        text.getFile(i_str);
        return i_str;
    }
}