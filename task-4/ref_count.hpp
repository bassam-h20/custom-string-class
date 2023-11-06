#pragma once
#include <iostream>
#include <cstring>

template <class X> class reference_count
{
public:
    //default constructor
    reference_count()
    {
        data = nullptr;
        ref_count = new int(1);
    }
    //constructor for passing in pointer for memory allocation
    reference_count(X* ptr)
    {
        data = ptr;
        ref_count = new int(1);
    }

    //copy constructor
    reference_count(const reference_count& s)
    {
        data = s.data;
        ref_count = s.ref_count;
        (*ref_count)++;
    }

    //copy assignment constructor
    reference_count& operator=(const reference_count& s)
    {   
        //check if assignment is not self-assignment
        if (this != &s)
        {
            (*ref_count)--;
            //if reference count is 0, release memory
            if (*ref_count == 0)
            {
                delete data;
                delete ref_count;
            }
            data = s.data;
            ref_count = s.ref_count;
            //increment reference count for new occurence
            (*ref_count)++;
        }
        //return pointer referring to the altered string
        return *this;
    }

    //to access members of object pointers, in this case objects of another class
    X* operator->() const
    {
        return data;
    }

    //allows to dereference an object
    X* operator*() 
    {
        return data;
    }

    //destructor
    ~reference_count()
    {
        (*ref_count)--;
        if (*ref_count == 0)
        {
            delete data;
            delete ref_count;
        }
    }

    //print function to print data and reference count
    void print()
    {
        std::cout << *data << " [" << *ref_count << "]" << std::endl;
    }

private:
    X* data;
    int* ref_count;
};
