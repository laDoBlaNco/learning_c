/*
Other Format Specifiers in C

Apart from the common format specifiers for integers and floating-point numbers, there are
several other format specifiers that are used for handling characters, strings, memory addresses
and even tracking the number of characters printed

    1. %c: character format specifier
    The %c format specifier is used for printing or scanning a single char. It reads or writes
    a single char from a given var. 

    2. %s: String Format specifier
    The %s format specifier is used for printing or scanning strings in C. A string is a sequence of
    characters terminated by a special null character '\0'. This format specifier reads or writes
    strings from or to variables. 

    3. %p: Pointer Format Specifier
    The %p format specifier is used for printing memory addresses or pointers. In C, pointers are
    variables that store memory addresses or other variables. To obtain the memory address of a var
    we use the address_of operator &

    4. %n: Number of chars printed
    The %n format specifier is unique becasue it is not used to print any values. Instead, it is used
    to store the number of chars printed so far by the printf function into an integer variable
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 'g';
    char b[] = "gfg";
    puts("");
    printf("%c %s %p\n",a,b,&a);
    puts("");

    int x;
    printf("abc %n cd \n",&x); // so here we are counting chars printed up to that point %n and
    // like scanf, putting that into x with the &x
    printf("The value of x is %d",x); // here we print the result

    return 0;
}
