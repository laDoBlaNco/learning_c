/**
 * If Statements: 
 * 
 * Work as expected. C++ also has the ternary operator ?: which works as expected as well.
 * 
 */

 #include <iostream>

 int main()
 {
    std::string name = "Kevin";
    int age = 17;
    bool bd = true;

    if(age>=18)
    {
        std::cout << "You may enter for 60 mins" << std::endl;
    }else if(bd){
        std::cout << "You may enter for 20 mins" << std::endl;

    }else{

        std::cout << "YOU MAY NOT ENTER" << std::endl;
    }
    
    std::cout << "Thank you for visiting" << std::endl;


    return  0;
 }