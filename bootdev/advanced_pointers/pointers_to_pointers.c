/**Pointers to Pointers
 * 
 * So now that I've learned a lot about pointers, let's learn it
 * all over again with pointers to pointers. in my studys at 
 * low_level_academy I learned that this is practical when we 
 * need to connect functions. Mainly due to the fact that its not
 * viable to return anything larger than a word size. so unless
 * its an int or bool or char, etc, then we need to use **ptrs. 
 * 
 * wormholes, doorways, portals, networks connecting functions
 * and their results to push data through. since we are working
 * with functions that live and die on the stack, these are all
 * malloc'd as well. 
 * 
 * Let's get'ur done. 
 * 
 * Pointer pointers are just a pointer variable that holds the address
 * of another pointer. This allows me to create complex data structures
 * like arrays of pointers, and to modify pointers indirectly. 
 * 
 * Syntax is as i would expect with an extra layer pretty much.
 * Pointers to pointers (or even pointers to pointers to pointers)
 * are like a treasure map or a scavenger hunt. I start at one pointer
 * and keep following the chain of addresses or the doorways until
 * I get to the final value. Its just a chain of dereferences. 
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/V02gw1W.png
 * 
 * Assignment: 
 * 
 * Complete the allocate_int function. Accept a pointer to a pointer
 * to an int. Change the value of pointer_pointer's pointer's address
 * to point to a new memory that has the value of the int. 
 *  1. Allocate memory for a single integer on the heap, and save
 *     its address into a new pointer
 *  2. Update the memory address that pointer_pointer is pointer to,
 *     to be the address of the new pointer. 
 *  3. Set the raw value of the inter that pointer_pointer now points
 *     to (well, that it points to through 2 address hops, portals, 
 *     or doorways) to the value passed in. 
 * 
 * NOTE that in this example the original value still exists at its
 * spot in memory, I just don't point to it anymore. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void allocate_int(int **,int);

int main(int argc, char const *argv[])
{
    // example
    // int value;
    // int *pointer;
    // int **pointer_pointer;

    // Assignment:
    int *ptr1 = NULL;
    allocate_int(&ptr1,10);
    printf("Should assign value to ptr1 of 10 and the value is %d\n",*ptr1);

    int val2 = 5;
    int *ptr2 = &val2;
    allocate_int(&ptr2,20);
    printf("\nShould not overwrite original value of 5 which is now %d\n",val2);
    printf("Should assign value to pointer of 20 and the value is %d\n",*ptr2);

    return 0;
}

void allocate_int(int **pointer_pointer, int value) {
    int *ptr = malloc(sizeof(int));
    // *pointer_pointer = &ptr; // leaving this bug here as a reference
    // below the correct version
    *pointer_pointer = ptr; // the actual pointer not the address of ptr
    **pointer_pointer = value;
}

// I had to see the solution on this one, but it was a pretty simple 
// bug. On line 74, I'm opening the door to my pointer_pointer but 
// I'm placing there the address of the new ptr on the heap, not the 
// address of the actual memory in heap, if that makes sense. When
// I malloc it get an address to the new allocated memory as the 
// value of int *ptr. But int *ptr has its own address. So on line 74
// I was putting that in *pointer_pointer instead of the address
// in that ptr.
