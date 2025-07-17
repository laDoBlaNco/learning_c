/**
 * User Input
 * 
 * Now we need to get input from some user. There are 2 ways to get user input
 * to start with. 
 * 
 * cin (console input) but its only good for one word since the delimiter is the space
 * after your input, but we can string them together as below.
 * 
 * Another way is using getline(std::cin,var)
 * 
 * Something I noticed and then steve explained is that you can't use them together off the cuff
 * apparently because cin is a buffer and since getline uses cin, its using that buffer and creates
 * a clash
 * To get past this we use cin.ignore() to ignore the cin in the buffer already
 * 
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "Please enter your age and name: ";
    int age;
    std::string name;
    std::cin >> age >> name;

    std::cout << "You are " << age << " years old." << std::endl;
    std::cout << "And your name is " << name << std::endl;

    std::cin.ignore();

    std::cout << "Please enter your description: ";
    std::string desc;
    std::getline(std::cin, desc);

    std::cout << "Description: " << desc << std::endl;

    return 0;
}