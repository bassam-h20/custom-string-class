#include <iostream>
#include <cstring>
#include "my_string.hpp"

my_string::my_string()
{
    data = nullptr;
    size = 0;
    ref_count = new reference_count();
}

my_string::my_string(const char* str)
{
    data = nullptr;
    size = 0;
    ref_count = new reference_count();
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

my_string::my_string(const my_string& s)
{
    data = s.data;
    size = s.size;
    ref_count = s.ref_count;
    ref_count -> increment();
}

my_string& my_string::operator=(const my_string& s)
{
    if(this != &s)
    {
        if(ref_count -> get_count() == 0)
        {
            delete[] data;
            delete ref_count;
        }
        else
        {
            ref_count -> decrement();
        }
        data = s.data;
        size = s.size;
        ref_count = s.ref_count;
        ref_count -> increment();
    }
    return *this;
}

my_string::~my_string()
{
    if(ref_count -> get_count() == 0)
        {
            delete[] data;
            delete ref_count;
        }
    else
        {
            ref_count -> decrement();
        }
}

char my_string::getChar(const int& i) const
{
    if (i>=0 && i < size)
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
    std::cout << data << " [" << ref_count->get_count() << "]" << std::endl;
}

