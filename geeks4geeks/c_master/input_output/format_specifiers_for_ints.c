#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*Format specifier for Integers in C
    
    In C programming, format specifiers are used in functions like
    printf and scanf to read and write data. They are used as a 
    placeholder in the format string for input AND output with
    printf, scanf, and similar functions. There are 8 integer specifiers
    in C
    
        ▫️ %d -- signed integer -- used for printing or reading signed ints
           supporting both positive and negative values
        ▫️ %u -- unsigned integer -- used for storing only positive numbers
          or zero, effectively doubling the integer range
        ▫️ %ls -- long integer -- used for larger ints when normal ints 
          can't hold the required value
        ▫️ %lld -- long long int -- used for even larger ints, offering 
          wider ran than %ld
        ▫️ %zd -- Size of Data Type -- Used for printing size_t values, 
          typically representing the size of objects or arrays
          NOTE: didn't see %zu but assuming its the same as this but
          unsigned
        ▫️ %x or %X -- Hexadecimal Representation -- Prints ints in 
          hexadecimal format: %x for lowercase (a-f) and %X for uppercase
          (A-F)
        ▫️ %o -- octal representation -- prints ints in octal (base 8) format
          with an optional prefix
        ▫️ %i -- integer input -- similar to %d but can read decimal, octal
          and hexadecimal numbers. If input starts with 0x or 0, it is treated
          accordingly. 
        */

    int x = 10;
    printf("%d\n",x);

    long y = 20;
    printf("%ld\n",y);

    unsigned z = 30;
    printf("%u \n",z);

    long long w = 40;
    printf("%lld\n",w);

    size_t u = sizeof(x);
    printf("%zd\n",u);

    return 0;
}
