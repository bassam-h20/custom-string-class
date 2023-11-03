#include <iostream>
#include <cstring>
#include "my_string.hpp"

//constructor for initializing without parameters
my_string::my_string()
{
    data = nullptr;
    size = 0;
}

//constructor for initializing from a string
my_string::my_string(const char* str)
{
    size = strlen(str);
    //allocates memory for string with null terminator
    data = new char[size + 1];
    //copy string to allocated memory
    strcpy(data, str);
}

//copy constructor to create a copy of the original string
my_string::my_string(const my_string& s)
{
    size = s.size;
    data = new char[size + 1];
    //copy the data from original string
    strcpy(data, s.data); 
}

//copy assignment constructur for assigining original string to this one
my_string& my_string::operator=(const my_string& s)
{
    //check if source and destination string don't match
    if(this != &s)
    {
        size = s.size;
        strcpy(data, s.data);
    }
    //return a pointer referring to the altered strinb
    return *this;
}


my_string::~my_string() {}

//get the char at a specific index in the string
char my_string::getChar(const int& i) const
{
    if(i >= 0 && i < size)
    {   
        return data[i];
    }
    //return null terminator if index is out of range
    return '\0';
}

//set char at a specific index in the string
void my_string::setChar(const int& i, const char& c)
{
    if(i >= 0 && i < size)
    {
        data[i] = c;
    }
}

//print function to output the string
void my_string::print() const
{
    std::cout << data << std::endl;
}

