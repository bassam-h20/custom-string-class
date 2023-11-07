#include <iostream>
#include <cstring>
#include "my_string.hpp"
#include "ref_count.hpp"

int main()
{   
    //test for my_string
    reference_count<my_string> s(new my_string("Hello"));
    s.print();
    {
        reference_count<my_string> s2(s);
        s.print();
        s2.print();
        std::cout << "s2: " << s2->getChar(1) << std::endl;
        s.print();
        s2.print();
    }
    s->setChar(1, 'a');
    s.print();

    //test for int
    reference_count<int> i(new int(5));
    i.print();
    {
        reference_count<int> i2(i);
        i.print();
        i2.print();
    }
    i.print();

}