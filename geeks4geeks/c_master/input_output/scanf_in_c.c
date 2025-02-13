#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    /*scanf() in C
    
    The scanf function in C is the counterpart to printf used to read
    input from the user. It can handle various data types such as 
    integers, characters, strings, and other primitive types.
    
    How to use?
    
    The scanf() reads input from the standard input device (keyboard)
    and stores in in variables
    syntax = scanf("format_string",address_of_argument);
    
    The format string in scanf contains placeholders similar to printf
    but it expects the addresses of variables as arguments. The address
    of any variable can be determined by using the & addressof operator
    before the variable name.
    
    &variable_name*/
    // int x,y;
    // printf("Enter first number: \n");
    // scanf("%d",&x);

    // printf("Enter second number: \n");
    // scanf("%d",&y);

    // printf("Sum is %d\n",x+y);

    /*Strings and scanf()
    
    Strings are stored as character arrays in C, so when reading strings,
    the variable name itself acts as the address (since strings are char
    arrays, so basically pointers) so the & operator is not required.*/

    // char name[100];
    // printf("Enter your name: \n");
    // scanf("%s",name);
    // printf("Hi %s.\n",name);
    // printf("Welcome go GfG\n");

    /*However scanf stops reading a string when it encounters a whitespace
    For reading strings with spaces, use fgets instead*/
    // char name[100];
    // printf("Enter your first and last name: \n");
    // scanf("%s", name); // only reads the first name

    // printf("Hi %s, \n", name);
    // printf("Welcome to GfG\n");

    /*Multiple Inputs for Scanf()
    
    You can read multiple values in a single scanf statement by specifying
    multuple placeholders*/
    // int x,y;
    // printf("Enter two numbers: \n");
    // scanf("%d %d",&x, &y);
    // printf("Multiplication is %d\n",x*y);
    // NOTE: Due to the space thingy, you can enter those two numbers
    // with an (enter) in between or like 66 66 (enter) and they will
    // work the same.

    /*Input Format with Separators
    If you include separators (e.g., strings) in the format string,
    the user must input the exact separator for the scanf function
    to work correctly. This is the reason why when I put \n in my first
    attempts, it wasn't working. It was waiting for me to add in \n 
    */
   int x,y;
   printf("Enter two numbers: \n");
   scanf("%dGfG%d",&x,&y);
   printf("Multiplication is %d\n",x*y);
   // if the input doesn't match the format string then the compiler 
   // will give undefined behavior.


    return 0;
}
