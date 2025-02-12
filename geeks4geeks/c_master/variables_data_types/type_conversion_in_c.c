#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    
    /*Type Conversion in C
    
    In C, type conversion refers to the process of changing one data
    type into another. This conversion can only occur between compatible
    data types. This conversion can be of two types: 
    
            🔹 Implicit (Done by the compiler)
            🔹 Explicit (Done by the programmer)
    
    Implicit Conversion
    
    Implicit conversion, also known as type promotion, occurs when the
    compiler automagically converts smaller or lower data types to a 
    larger or higher one during an operation. This ensures no loss of
    information (except when explicitly stated) But when converting 
    larger data types to smaller ones, it can cause loss of information.
    
    For example when conveerting a float to an int, there is a los of 
    information during the process*/
    float x = 10.5;
    int y = x;
    printf("%d\n",y); // 10.5 converted to 10
    bool z = y;
    printf("%d\n",z); // 10 converted to 1

    /*When dealing with an expression that includes multiple types the
    given rule of conversion is followed
        bool -> char -> short int -> int -> unsigned int ->long -> long ->
        unsigned -> long long -> float -> double -> long double
        
    if int has a negative value, the negative value is stored in 2's 
    complement. If type conversion happens in int to unsigned than 2's 
    complement representation is considered as it is in the unsigned
    variable*/


    /*Examples of Implicit Conversion*/
    int a = 10;
    float b = 10.5;
    float c = a + b;
    printf("%f\n",c);
    // In the expression "float z=x+y", integer x is promoted to float

    char d = 'B';
    double e = 10.5;
    double f = d + e;
    printf("%g\n",f);
    /*The character 'B' is converted to its ASCII value (66), and the
    operation is performed in the double data type*/

    /*Explicit Conversion
    
    Explicit conversion, or typecasting is done explicitly by the programmer
    according to the requirement. 
    
    Syntax:
        (type) expression;*/
    
    int g = 15, h = 2;
    double i = g/h;
    printf("%g\n",i);
    /*In the above code, both g and h are integers. When g is divided
    by h, the calculation is performed as integer division, and the
    expected result is 7.5 but I get 7 because the calulation happens
    THEN integer is assigned to the variable double i. So I lose some
    data in this process.
    
    To resolve this I can convert g into double using explicit convesion:*/
    i = (double)g/h;
    printf("%g\n",i); // now I get the expected result of 7.5
    // as g is explicitly converted to 15.0 and then h is promoted to 2.0
    


    return 0;
}
