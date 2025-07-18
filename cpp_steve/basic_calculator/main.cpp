/**
 * Basic Calculator:
 * 
 * 
 */

#include <iostream>

double add(double num1, double num2)
{
   return num1+num2;
}

double div(double num1, double num2)
{
   return num1/num2;
}


int main(int argc, char* argv[])
{ 
   
   double num1, num2; // both are doubles
   char op;
   
   std::cout << "Please enter the first number: ";
   std::cin >> num1;
   std::cout << "What would you like to do?" << std::endl;
   std::cout << "+ -> addition\t- -> subtraction" << std::endl;
   std::cout << "/ -> division\t* -> multiplication" << std::endl;
   std::cout << "Operation choice: ";

   std::cin >> op;

   std::cout << "Please enter the second number: ";
   std::cin >> num2;

   if (op == '+')
   {
      std::cout << "The answer is " << add(num1,num2) << std::endl;     
   } else if(op == '-')
   {
      std::cout << "The answer is " << num1 - num2 << std::endl;  
   } else if(op == '/')
   {
      std::cout << "The answer is " << div(num1,num2) << std::endl;     

   }else{
      std::cout << "The answer is " << num1 * num2 << std::endl;
   }
   


   return 0;
}