/**Double Pointers Exercise
 * 
 * Objective:
 * In this challenge, I'm reviewing the basics of double pointers
 * in C. In many of the problems in C, I'll need to have a solid
 * grasp of the pointer syntax and using pointers to pass data
 * between functions. Double pointers are used in code that requires
 * a memory address to be updated by another function. This is 
 * common when I'm passing around a buffer that may need to be 
 * resized by a called function, or a structure that need to be
 * populated. 
 * 
 * Task, Fix the code below. The function takes a pointer to a pointer
 * Write a valid heap allocated memory address to that parameter. 
 * Before the function returns, write the number 10 to that location
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/** Correct this code to update the value in the heap to 10
 * before giving the address to main
 */
int foo(int **ptr) {
    int value = 10;
    // just by adding the (*) here to ptr. remember that **ptr is 
    // like a tunnel. the first * opens the tunnel and the second * takes
    // me to the value I need to access. so this line below is what 
    // creates the **ptr so that I can later open the tunnel to the
    // allocated memory and place our value in it.
    *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    **ptr = value;
    return 0;
}