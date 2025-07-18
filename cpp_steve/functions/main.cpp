/**
 * 
 * Functions
 * 
 * our 'main' portion of the program is a funcion, the principal function. But we can make others
 * as expected. 
 * 
 * Nothing unexpected here that I haven't learned from other languages
 * 
 * Also there is no function hoisting in C or Cpp, so if we want to keep main on top we need to  
 * use function declarations prior to calling the functions or the definition
 * 
 * One thing I learned with the function declarations and the use of default args. We have to put the 
 * default in the function declaration only. If its in the definition only or in both, it will error out.
 * 
 * NOTE: Something I've noticed but only now commenting about it is that the 'string' is used with std::
 * but other types are not. I'm assuming this is because being a superset of C, C already has types
 * bool, int, float, char, but there is no string. So std::string is the cpp version of string in the
 * standard lib.
 */

#include <iostream>

// function declarations:
void sayHello();
void sayHello2(std::string name = "Kevin");
float sum(float,float);
int cube(int);

int main(int argc, char *argv[])
{

   sayHello();
   sayHello2("Ladoblanco");
   sayHello2(); // it'll use our default arg
   sayHello2("Odalis");
   sayHello2("Kelen");
   sayHello2("Xavier");

   std::cout << sum(60.1,6.758) << std::endl;
   std::cout << cube(5) << std::endl;

   return 0;
}
 
void sayHello() // void just means nothing is returned
 {
    std::cout << "Hello!" << std::endl;
 }

 void sayHello2(std::string name)
 {
    std::cout << "Hello " << name << "!" << std::endl;
 }

 float sum(float num1, float num2)
 {
    std::cout << "Calculating..." << std::endl;
    return num1 + num2;
 }

 int cube(int num)
 {
    return num*num*num;
 }
