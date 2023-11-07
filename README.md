# ASP Worksheet 1

## Simplified string class and reference counting

### **<u>Task 1**</u>
* This task revolved around developing a simple version of C's string class using dynaminc memory allocation, copy assignment & copy constructors. The class "my_string", is a custom string class implemented to create, modify and print strings

* The class "my_string" contains methods that carry out difference functions. These functions mainly consist of initializing a string from a C language style character array and calculates the size of the string, allocates memory for it and copies the content. 

* Other methods include "getChar()" which returns the character at a specific index in the string and "setChar()" sets the character at specific index in the string

To compile & run:
```
clang++ test_string.cpp my_string.cpp -o test_string; ./test_string
```

output:

![running task 1 screenshot](./images/WS1-T1.png)

---

### <u>**Task 2**</u>
* This task was about extending the string class to automate the process of reference counting, by print the test strings, with the reference count printed right after in the format "string [reference count]"

* This was done by initializing a reference count variable in the header file(my_string.hpp) and incrementing or decrementing it depending on the action needed in each method in the my_string class

To compile & run:
```
clang++ test_string.cpp my_string.cpp -o test_string; ./test_string
```
output:

![running task 2 screenshot](./images/WS1-T2.png)

---
### <u>**Task 3**</u>
* This task is solely to demonstrate when the reference count reaches 0. The only thing that was changed from the previous task was adding an if statement for when the reference count reaches to 0, and printing it

to compile & run:
```
clang++ test_string.cpp my_string.cpp -o test_string; ./test_string
```

output:

![running task 3 screenshot](./images/WS1-T3.png)

---
### <u>**Task 4**</u>
* This task was to implement reference counting outside the my_string class and in a seperate header file (ref_count.hpp). That was done using a template class with methods that allow reference counting in the main.cpp file

* For this task, a template class was implemented to help manage reference counting for some data. It holds a pointer to the object of type X, and keeps count of the number of references to that object. This reference counting class is made to work with any class.

* To test the implementation, two tests were put in place. One for the my_string class, and one for int, as shown here:
![test file code](./images/WS1-T4(2).png)

to compile & run:
```
clang++ main.cpp my_string.cpp -o main
```

![running task 4 screenshot](./images/WS1-T4.png)


