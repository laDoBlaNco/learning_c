/** Operator sizeof() in C
 * 
 * In C, sizes of different primitive data types can vary depending
 * on the compiler. If I want to know the size of a particular data
 * type on my compiler, C provides the 'sizeof' operator to determine
 * it. It returns the memory required by given variable, data type, 
 * or literals in bytes. The type of the result is 'size_t' which
 * I think of as a generic size type that will fit the largest possible
 * result I would get back. 
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%zu \n", sizeof(int));
    printf("%zu \n", sizeof(char));
    printf("%zu \n", sizeof(long long));
    printf("%zu \n", sizeof(float));

    printf("\n");

    // I can also use the sizeof operator with variables and literals
    // just like data types
    int x = 10;
    double d = 11.5;

    printf("%zu \n", sizeof(x));
    printf("%zu \n", sizeof(d));
    printf("%zu \n", sizeof(15LL)); // I've never see this notation
    printf("%zu \n", sizeof(13.6f)); // what is this 'f' and 'LL' 🤔
    // The professor says I'll get into the details of this notation of
    // literals later, but in essence literal notation means we can put
    // the type after the number so above is LL=long long and f = float, If
    // I remove 'f', then the assumed size of literal decimals are double.
    // so 13.6f = 4bytes while 13.6 = 8bytes

    printf("%zu \n", sizeof(x + 10));

    printf("\n");

    /* sizeof Operator  determines the size of the given variable, 
    literal or expression at compile time and the expressions are 
    not executed. It just deduces the size from the return type of
    the expression. It is shown in the below example:*/
    printf("%zu \n", sizeof(x++));
    printf("%u \n", x);
    // so the interesting above is that the expresion x++ didnt happen
    // that's why x is still 10. compiler deduced the resulting type size
    // but didn't run the expression 🤯


    return 0;
}
