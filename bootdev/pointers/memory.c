/**Memory
 * 
 * Before I jump into pointers, I need to understand variables
 * and memory in general. just to have everything kinda in a 
 * mental model. 
 *  - Variables are human readable names that refer to some data in
 *    memory
 *  - Memor is a big array of bytes, and data is stored in the array
 * 
 * A variable is a human readable name that refers to an ADDRESS in
 * memory, which is an index into the big array of bytes. This would
 * mean that variables are just POINTERS to bytes in memory
 * 
 * Would it be better for me to think of variables as pointrs to
 * the FIRST byte of my data and the size of the data type is used
 * with pointer arithmetic to get the whole block??? Kinda like 
 * arrays??? I guess the fact that we have to use the & to create
 * a pointer tells me that the var itself isn't actually a pointer
 * as in the case of arrays. And if I try to use the %p on the 
 * actual var name I get an error, which is different behavior than
 * with array names. So C is doing something under the hood that I
 * don't quite understand yet, but I'm close. 🤔🤔🤔
 * 
 * I think it would have to be since the address returned by a
 * variable is only 1 number referring to one slot or byte. The 
 * starting point If I will. 🤯
 * 
 * Now getting back into the pointer semantics, I can print the 
 * address that is actually inside the variable by using the
 * address-of-operator '&'
 * 
 * NOTE: The use of the %p format specifier formats the pointer 
 * (memory address) to be printed.
 * 
 */
#include <stdio.h>

unsigned long size_of_addr(long long);

int main(int argc, char const *argv[])
{
    int age = 48;
    printf("The address of age is: %p\n",&age);
    printf("While the value of age is: %d\n",age);

    // Assignment get the size of the address not the size of
    // the value.
    printf("Size of sneklang address: %zu\n",size_of_addr(128));

    return 0;
}

unsigned long size_of_addr(long long i)
{
    unsigned long sizeof_snek_version = sizeof(&i);
    return sizeof_snek_version;
}

// I might be getting ahead of myself here but this assignment 
// makes me think about these addresses and how they are determined. 
// for example if an address is 0x7fff9c512554, then while it makes
// sense that the next address would be 4 or 8 bytes later maybe
// My question is how does that correlate with the size of the address
// does the sizeof address point to the actual byte or is it that byte
// plus the size of the value, etc??? 
