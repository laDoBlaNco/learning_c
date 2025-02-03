/**Malloc
 * 
 * The malloc function (Memory ALLOCation) is a standard lib function
 * in C that allocates a specified number of bytes of memory on the
 * heap and returns a pointer to the allocated memory. 
 * 
 * This new memory is uninitalized, which means: 
 *  1. It contains whatever data was previously at that location
 *  2. It is my responsibility to ensure that the allocated memory
 *     is properly initialized (and casted) and eventually freed using 'free'
 *     to avoid memory leaks.  
 * 
 * If I want to make sure that the memory is propery initialized, 
 * I can use the calloc function, which allocates the specified
 * number of bytes of memory on the heap and returns a pointer to
 * the allocated memory. This memory though is initialized to zero
 * (meaning it contains all zeros). 
 * 
 * Function Signature: 
 * void *malloc(size_t size): 
 *  ▫️ size: the number of bytes to allocate
 *  ▫️ Returns: a pointer to the allocated memory or NULL if the 
 *    allocation fails (that's why we use an if clause to check the
 *    result)
 * 
 * Example below:
 * 
 * NOTE: NULL POINTER VS VOID POINTER
 * A "null pointer" represents a special value indicating that a 
 * pointer does not point to any valid memory location, essentially 
 * meaning "nothing", while a "void pointer" is a type of pointer 
 * that can point to any data type, meaning it has no specific type 
 * associated with it; essentially, a null pointer is a value used 
 * to signify no memory address, whereas a void pointer is a type 
 * of pointer that can be cast to any other type of pointer.
 * Meaning: 
 * A null pointer is a value used to indicate that a pointer is not 
 * pointing to any memory location, while a void pointer is a pointer 
 * type that can hold the address of any data type.
 * Usage:
 * I use a null pointer to check if a pointer is not pointing to 
 * a valid memory location, while a void pointer is used to create 
 * generic functions that can handle any type of data. 
 * Example: int *ptr = NULL  ---   void *ptr;
 * 
 * Manual Memory Management
 * This idea of manually calling malloc and free is what puts the
 * 'manual' in 'manually managing memory'. That's actually pretty
 * simple. I've always thought it was more complicated than that 🤔
 *  ▫️ I must remember to eventually free the allocated memory using
 *    free(ptr) to avoid memory leaks
 *  ▫️ Otherwise, that allocated memory is never returned to the 
 *    OS for use by other programs, (until the program exits at
 *    which point the OS will clean up after it, but that's not 
 *    ideal) Hence a MEMORY LEAK
 * Manually managing memory can be error-prone and tedious, but 
 * languages that automatically manage memory (like Python, Java, 
 * and C#) have their own trade-offs, usually in terms of
 * performance. 
 * 
 * Assignment: 
 * I'll evenutally be building a garbage collector. 
 *  1. Complete the allocate_scalar_list function. It should: 
 *      ▫️ Accept size and multiplier parameters and should allocate
 *        an array of size integers on the heap (sizeof(int))
 *      ▫️ Gracefully return NULL if the allocation fails
 *      ▫️ Initialize each element in the list of index *multiplier
 *        (e.g., a multiplier of 2 would result in [0,2,4,6,...])
 *      ▫️ Return a pointer to the allocated memory
 */

#include <stdio.h>
#include <stdlib.h>

int *allocate_scalar_list(int,int);

int main(int argc, char const *argv[])
{

    int array[100];
    printf("sizeof array is %zu\n",sizeof(array)/sizeof(*array));
    for (int i = 0; i < sizeof(array)/sizeof(*array); i++) {
        printf("Array [%d] = %d\n",i,array[i]);
    }
    // EXAMPLE:
    int *ptr = malloc(10 * sizeof(int));
    if (ptr == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    // use the memory here
    printf("sizeof(ptr) = %zu\n",sizeof(ptr));
    printf("sizeof(*ptr) = %zu\n",sizeof(*ptr));
    for (int i = 0; i < 10; i++) {
        ptr[i] = i*i;
    }
    for (int i = 0; i < 10; i++) {
        printf("Element %d = %d\n",i,ptr[i]);
    }
    free(ptr);

    // ASSIGNMENT: 
    int size = 5;
    int multiplier = 2;
    int *result = allocate_scalar_list(size, multiplier);
    printf("expected[0] = 0 and it is %d\n",result[0]);
    printf("expected[1] = 2 and it is %d\n",result[1]);
    printf("expected[2] = 4 and it is %d\n",result[2]);
    printf("expected[3] = 6 and it is %d\n",result[3]);
    printf("expected[4] = 8 and it is %d\n",result[4]);

    return 0;
}

int *allocate_scalar_list(int size, int multiplier) {
    int *result = malloc(size * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        result[i] = i * multiplier;
    }
    return result;

}
/**
 * I took a bit longer with this one because there is some tricky 
 * stuff when working with pointers in for loops and using sizeof
 * I'm still not 100% clear but it seems that the array is decayed
 * to a simple pointer in the for loop and therefore sizeof gives 
 * me not the length of the loop but the size of the first element
 * or the size of the actual address depending if I use sizeof(ptr)
 * or sizeof(*ptr). But apparently that's not it either cuz that
 * array I have in main first doesn't decay. Maybe it has something
 * to do with the malloc pointer and not being an actual array on
 * the stack ??? 🤔🤔🤔
 * 
 * It must be that. malloc returns a pointer, not an actual array
 * so technically I'm never actually working with an array. So all
 * the passing around I'm doing is with a pointer, never an array,
 * meaning I never actually have the full size info of the actual
 * array just the first pointer, size of the address and what that 
 * first pointer holds. 
 * 
 * 
 */
