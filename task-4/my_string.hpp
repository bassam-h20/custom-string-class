#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <class T> class reference_count
{
public:
    reference_count() : count(1){}
    void increment() {count++;}
    void decrement() {--count;}
    int get_count() const {return count;}
private:
    int count;
};

class my_string
{
public:
    my_string();
    my_string(const char *);
    my_string(my_string const& s);
    my_string& operator= (my_string const& s);
    ~my_string();

    char getChar(const int& i) const;
    void setChar(const int& i, const char& c);
    void print() const;

private:
    char* data;
    size_t size;
    reference_count<my_string> *ref_count;
};