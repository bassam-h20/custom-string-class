#pragma once

class reference_count
{
public:
    reference_count() : count(1){}
    void increment() {count++;}
    void decrement() {count--;}
    int get_count() const {return count;}
private:
    int count;
};