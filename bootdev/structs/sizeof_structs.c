/**Sizeof in Structs:
 * 
 * I saw earlier that with sizeof I can view the size of a type
 * but this isn't true for just the built-in types. I can also use
 * it to find out info about my structs as well.
 * 
 * Memory Layout:
 * I learned a lot about his with my course in Google Go's GC. It 
 * gave me a moderate understanding of alignment and memory caching
 * etc. Structs are stored contiguously in memory one field after 
 * another. So one would assume that the resulting size of the struct
 * would just be the sum of all the parts int + int + int (4 + 4 + 4)
 * 
 * This may be the case typically when dealing with the same types,
 * But when you start working with different types, then alignment
 * and padding gets into the picture.
 * 
 * Mixed Type Structs:
 * Assuming our struct below has char (1byte), int (4byte) and double (8byte)
 * One might say its 13 bytes??? But atually one would probably find
 * 'padding' included. CPUs don't like accessing data that isn't aligned
 * so C inserts padding to maintain alignment (e.g. every 4  bytes in 
 * the example below)  NOTE: layouts can vary depending on the arch.
 * 
 * NOTE: That alignment is based on the word bounderies, which are just
 * the way memory is normally split up by the arch. Normally either 
 * in bytes of 4 or 8. The smallest word typically being 4. So if
 * a char is only 1byte, C will adding 3bytes of padding to get to
 * at least 4.
 */

#include <stdio.h>

typedef struct Coordinate
{
    int x;
    int y;
    int z;
} coord_t;

typedef struct Human
{
    char first_initial;
    int age;
    double height;
} human_t;

//=============================================================
int main(int argc, char const *argv[])
{
    printf("Size of coord_t: %zu bytes\n",sizeof(coord_t));
    printf("Expected size of human_t: %d\n",1+4+8);
    printf("Actual size of human_t: %zu\n",sizeof(human_t));
    return 0;
}


//============================================================

