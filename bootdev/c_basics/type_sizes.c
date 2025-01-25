/**Type Sizes
 * 
 * In C the size (in memory) of a type is not guaranteed to be the 
 * same on all systems. That's because the sie of a type is dependent 
 * on the system's arcitecture. For example, on a 32-bit system, the size
 * of an int is usually 4 bytes, while on a 64-bit system the size of
 * an int is usually 8 bytes - of course, i'll never really know until
 * I run 'sizeof' with the compiler I'm working with.
 * 
 * However some types are always guaranteed to be the same. here's a list
 * of the basic C data types along with their typical sizes in bytes. Note 
 * sizes can var based on the platform
 * 
 * Basic C Types and Sizes:
 * 
 *  - char
 *      - size: 1 byte
 *      - Represents: single character
 *      - Notes: always 1 byte, but can be signed or unsigned
 * 
 *  - float
 *      - Size: 4 bytes
 *      - Represents: Single-precision floating-point number
 * 
 *  - double
 *      - Size: 8 bytes
 *      - Represents: Double-precision floating-point number.
 * 
 * These actual sizes of these types can be determined using the
 * 'sizeof' operator in C fo ra specific platform
 * 
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c = 'c';
    float f = 3.14;
    double d = 31.098957342;

    printf("The size of the char is %ld\n",sizeof c);
    printf("The size of the char is %ld\n",sizeof f);
    printf("The size of the char is %ld\n",sizeof d);
    return 0;
}
