/**
 * Recursive Functions:
 * 
 * So a function that calls itself. So nothing out of the ordinary with the concept for me, but 
 * good to see how its formed in cpp
 */

 #include <iostream>

 int fact(int num)
 {
    if (num==1) // base case
    {
        return 1;
    }else{
        return num * fact(num-1); // recursion
    }
    
 }
 
 int main(int argc, char* argv[])
 {
    std::cout << fact(5) << std::endl;
    return 0;
 }