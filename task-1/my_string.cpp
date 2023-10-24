#include <iostream>
#include <cstring>
#include "my_string.hpp"

my_string::my_string()
{
    data = nullptr;
    size = 0;
}

my_string::my_string(const char* str)
{
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

my_string::my_string(const my_string& s)
{
    size = s.size;
    data = new char[size + 1];
    strcpy(data, s.data);
}

my_string& my_string::operator=(const my_string& s)
{
    if(this != &s)
    {
        size = s.size;
        strcpy(data, s.data);
    }
    return *this;
}

my_string::~my_string()
{
    delete[] data;
}

char my_string::getChar(const int& i) const
{
    if(i >= 0 && i < size)
    {
        return data[i];
    }
    return '\0';
}

void my_string::setChar(const int& i, const char& c)
{
    if(i >= 0 && i < size)
    {
        data[i] = c;
    }
}

void my_string::print() const
{
    std::cout << data << std::endl;
}

