/**Pointer Size
 * 
 * So the size of an array depends on both the number of elements
 * and teh size of each element. And since an array is just a
 * pointer, it makes me think about what size is the pointer? Though
 *  in reality the name of the array is only pointing to the first
 * element, so does it really matter?  Sorry I'm digressing
 * 
 * An array is a contiguous block of memory where each element has
 * a specific size. 
 * 
 * In C, pointers are always the same size becasue they just rep
 * memory addresses. The size of a pointer is determined by the arch
 * of teh system (32 or 64 bit). A pointer's size doesn't depend on
 * the type of data ti points to. True, I was think it about the
 * size of the first element but not even that matters since a ptr
 * value is the address itself therefore the pointer size is just
 * that address. It just holds the address of a memory location.
 * 
 * for example the first set below is all the same size becasue
 * I have a 64 bit system, no matter how much memory the value at
 * that address takes up.
 * 
 * so what about an array? So the arrays are different so they do
 * depend on something other than just the address size that the
 * arch determines 🤔.
 * 
 * The array type keeps track of the size of each element and the
 * number of elements. Although an array is a pointer to the first
 * element, IT'S NOT JUST A POINTER. IT'S A BLOCK OF MEMORY THAT
 * HOLDS ALL THE ELEMENTS. So even though the identifer points to
 * the address location of the first element, it still holds all
 * the elements meaning that the size does depend on what its 
 * holding. 
 * 
 * So om my system a pointer is 8 bits, but an array will be the 
 * size of an element * the number of elements. That's why
 *      - int_array = 4 bytes * 10 = 40
 *      - char_array = 1 byte * 10 = 10
 *      - double_array = 8 bytes * 10 = 80
 * 
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *int_ptr;
    char *char_ptr;
    double *double_ptr;
    printf("Size of int pointer: %zu bytes\n",sizeof(int_ptr));
    printf("Size of char pointer: %zu bytes\n",sizeof(char_ptr));
    printf("Size of double pointer: %zu bytes\n",sizeof(double_ptr));
    printf("\n\n");

    int int_array[10];
    char char_array[10];
    double double_array[10];
    printf("Size of int array: %zu bytes\n",sizeof(int_array));
    printf("Size of char array: %zu bytes\n",sizeof(char_array));
    printf("Size of double array: %zu bytes\n",sizeof(double_array));

    return 0;
}
