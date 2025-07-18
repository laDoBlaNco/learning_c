/**
 * Function Overloading
 * 
 * Here is where we get into some of the  stuff people hate about cpp. So I need to be careful
 * with the use of these things. 
 * 
 * OK, this is super cool. I didn't know about this piece. So something new por fin. In other languages
 * getting that to work would've taking more code or wouldn't be very intuitive. Even the output can 
 * be different, o sea, returning a value from one function and void from another with the same 
 * name all determined by the args used with the function. 
 * 
 * This shouldn't be used with the functions don't have anything to do with each other anymore. 
 * for example in other languages (ruby or python) you overload to change the function completely
 * 
 */

 #include <iostream>

 int sum(int x, int y)
 {
    return x + y;
 }
 double sum(double x, double y) // this adds meaning to the above function and cpp will know which
 // one you want to use
 {
    return x + y;
 }

 // another example using completely different types
 void sayHello(std::string name)
 {
    std::cout << "Hello, " << name << std::endl;
 }
 void sayHello(std::string name, int age)
 {
    std::cout << "Hello, " << name << ". You are " << age << " years old." << std::endl;
 }

 int main(int argc, char* argv[])
 {

    std::cout << sum(60,6) << std::endl;
    std::cout << sum(60.123456,6.987654) << std::endl;

    sayHello("Odalis");
    sayHello("Odalis",50);
    return 0;
 }