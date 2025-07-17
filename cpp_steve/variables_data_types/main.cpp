#include <iostream>

/**
 * Variables & Data Types:
 * Data types are just types of data that can be stored somewhere
 * For example:
 * chars 's','a','1'
 * ints 1, 2, 3
 * float/double 1.1, 2.2, 3.3
 * bools true/false used for adding logic to programs
 * strings "using double quotes and not ''" basically a string of chars
 * 
 * NOTE: we can get the size of a data type with 'sizeof'
 * 
 * Variables are basically containers for these data types
 * userName --> "Kevin"
 */

int main(int argc, char const *argv[])
{

    std::string mcName = "Kevin";
    int age = 48;

    std::cout << "\nMy name is " << mcName << " and I'm " << age << " years old" << std::endl;
    std::cout << "Tomorrow I'll be " << age + 1 << " years old" << std::endl;
    std::cout << "I want to change my name from "<< mcName << " to ladoBlanco" << std::endl;
    mcName = "LadoBlanco";
    age++;
    std::cout << "My new name is " << mcName << " and I'm still " << age << " years old" << std::endl;

    char letter = 'a';
    char number = 97; // also works with converting ascii chars --> 'a'
    bool old = false;
    float num = 3.14159;
    double x = 3.141591234565;


    return 0;
}