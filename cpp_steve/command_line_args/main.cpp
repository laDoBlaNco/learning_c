/**
 * Command-line Arguments
 * 
 * Another way of getting input is from the terminal in the form of user arguments with the command
 * or the file
 * 
 * This is done with the optional information we include in the ()s of int main(int argc, char const*argv[])
 */

 #include <iostream>

 int main(int argc, char const *argv[])
 {

    std::cout << argc << std::endl;
    std::cout << argv[2] << std::endl;
    return 0;
 }