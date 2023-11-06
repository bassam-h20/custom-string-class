#include <iostream>
#include <cstring>
#include "my_string.hpp"
#include "ref_count.hpp"

int main()
{
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
}