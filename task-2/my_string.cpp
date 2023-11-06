#include <iostream>
#include <cstring>
#include "my_string.hpp"

//constructor for initializing without parameters
my_string::my_string()
{
    size = 0;
    //allocate memory for empty string
    data = new char[size + 1];
    //initialize a reference count of for counting copies
    ref_count = new int(1);
}

//constructor for initializing a string
my_string::my_string(const char* str)
{
    size = strlen(str);
    //allocates memory for string with null terminator
    data = new char[size + 1];
    ref_count = new int();
    //copy string to allocated memory
    strcpy(data, str);
    //set the reference count to 1 as this is the first occurence
    *ref_count = 1;
}

//copy constructor to create a copy of the original string
my_string::my_string(const my_string& s)
{
    //copy data pointer, size and reference count
    data = s.data;
    size = s.size;
    ref_count = s.ref_count;
    //increment reference count to indicate another occurence of a copy
    (*ref_count)++;
}

//copy assignment constructor for assigning original string to another one
my_string& my_string::operator=(const my_string& s)
{   
    // check if assignment is not self-assignment
    if(this != &s)
    {
        if(*ref_count== 0)
        {
            delete[] data;
            //if reference count is 0, release memory
            delete ref_count;
        }
        else
        {    //decrement reference count if not 0
            (*ref_count)--;
        }
        data = s.data;
        size = s.size;
        ref_count = s.ref_count;
        //increment reference count for new occurence
        (*ref_count)++;
    }
    //return a pointer referring to the altered string
    return *this;
}

//destructor
my_string::~my_string()
{
    if(*ref_count == 0)
        {
            delete[] data; //if reference count is 0, release memory
            delete ref_count;
        }
    else
        {   //decrement reference count if not 0
            (*ref_count)--;
        }
}

//get the char at a specific index in the string
char my_string::getChar(const int& i) const
{
    //validate index is within range
    if (i>=0 && i < size)
    {
        return data[i];
    }
    //return null terminator if index is out of range
    return '\0';
}

//set char at a specific index in the string
void my_string::setChar(const int &i, const char &c)
{
    //validate index is within range
    if (i >= 0 && i < size)
    {
        data[i] = c;
    }
}

//print function to output string and its reference count
void my_string::print() const
{
    std::cout << data << " [" << *ref_count << "]" << std::endl;
}