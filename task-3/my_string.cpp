#include <iostream>
#include <cstring>
#include "my_string.hpp"

my_string::my_string()
{
    size = 0;
    data = new char[size + 1];
    ref_count = new int();
}

my_string::my_string(const char *str)
{
    size = strlen(str);
    data = new char[size + 1];
    ref_count = new int();
    strcpy(data, str);
    *ref_count = 1;
}

my_string::my_string(const my_string &s)
{
    size = s.size;
    data = s.data;
    ref_count = s.ref_count;
    (*ref_count)++;
}

my_string &my_string::operator=(const my_string &s)
{
    if(this != &s)
    {    if (*ref_count == 0)
        {
            delete ref_count;
            delete[] data;
        }

        data = s.data;
        size = s.size;
        ref_count = s.ref_count;
        (*ref_count)++;
    }
    return *this;
}

my_string::~my_string()
{
    *ref_count -= 1;
    if (*ref_count == 0)
    {
        //print called to demonstrate case of reference count of 0
        print();
        delete ref_count;
        delete[] data;
    }
}

char my_string::getChar(const int &i) const
{
    if (i >= 0 && i < size)
    {
        return data[i];
    }
    return '\0';
}

void my_string::setChar(const int &i, const char &c)
{
    if (i > 0 && i < size)
    {
        data[i] = c;
    }
}
void my_string::print() const
{
    std::cout << data << " [" << *ref_count << "]" << std::endl;
}