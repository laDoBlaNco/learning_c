/**
 * So far all I've seen in this course are simple (non-collection) types
 * in C. But then we have to do things like initialize 100s of data
 * points manually. In addition to that we can only return single
 * values from a function in C. I don't think there are any
 * tuples. 
 * 
 * Structs solve this problem. For example:
 * struct Human
 * {
 *    int age;
 *    char *name;
 *    int is_alive;
 * }
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct Coordinate
    {
        int x;
        int y;
        int z;
    };
    
    return 0;
}
