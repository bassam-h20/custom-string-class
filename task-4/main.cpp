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


    //test 2 for my_string using assignment
    printf("\n\nTesting with my_string class with assignment:\n");
    reference_count<my_string> s3(new my_string("Hello"));
    s3.print();
    {
        reference_count<my_string> s4(new my_string()); 
        s4 = s3;
        s3.print();
        s4.print();
        std::cout << "s4: " << s4->getChar(1) << std::endl;
        s3.print();
        s4.print();
    }
    s3->setChar(1, 'E');
    s3.print();


    //test for int
    printf("\n\nTesting with int class:\n");
    reference_count<int> i(new int(5));
    i.print();
    {
        reference_count<int> i2(i);
        i.print();
        i2.print();
    }
    i.print();

    
}
