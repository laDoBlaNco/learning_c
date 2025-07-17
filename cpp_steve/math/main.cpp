/**
 * Math
 * 
 */

 #include <iostream>
 #include <cmath> // this is used for some of the cpp math functions

 int main()
 {
    std::cout << 15 - 7 + 9 * 5 << std::endl;
    std::cout << 10 / 2 * 2 << std::endl;
    std::cout << 10 % 3 << std::endl << std::endl;

    std::cout << pow(5,2) << std::endl;
    std::cout << pow(5,3) << std::endl << std::endl;

    std::cout << sqrt(36) << std::endl;
    std::cout << sqrt(25) << std::endl << std::endl;

    std::cout << round(5.4) << std::endl;
    std::cout << round(5.5) << std::endl<<std::endl;;

    std::cout<<floor(5.4)<<std::endl;
    std::cout<<floor(5.6)<<std::endl<<std::endl;
    
    std::cout<<ceil(5.4)<<std::endl;
    std::cout<<ceil(5.6)<<std::endl<<std::endl;

    std::cout << fmax(5,10) << std::endl;
    std::cout << fmin(5,10) << std::endl;
 }