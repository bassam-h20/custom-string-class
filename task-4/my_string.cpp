#include <iostream>
#include <cstring>
#include "my_string.hpp"

//default constructor
my_string::my_string()
{
    data = nullptr;
    size = 0;
}

//constructor for initializing a string
my_string::my_string(const char* str)
{
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

//copy constructor to create a copy of the original string
my_string::my_string(const my_string& s)
{
    size = s.size;
    data = new char[size + 1];
    strcpy(data, s.data);
}

//copy assignment constructor for assigning original string to another one
my_string& my_string::operator=(const my_string& s)
{   
    //check if assignment is not self-assignment
    if(this != &s)
    {
        size = s.size;
        strcpy(data, s.data);
    }
    //return pointer referring to the altered string
    return *this;
}

//destructor
my_string::~my_string() {    
    delete[] data;

}

//
std::ostream& operator<<(std::ostream& os, const my_string& s)
{
    os << s.data;
    return os;
}

//get the char at a specific index in the string
char my_string::getChar(const int& i) const
{   
    //validate index is within range
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
    //validate index is within range
    if(i >= 0 && i < size)
    {
        data[i] = c;
    }
}

//print function to output string
void my_string::print() const
{
    std::cout << data << std::endl;
}

