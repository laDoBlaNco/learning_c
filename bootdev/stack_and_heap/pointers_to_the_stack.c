/**Pointers to the Stack
 * 
 * So I know that stack frames are awlays getting pushed and popped
 * and as a result, memory addresses on the stack are always changing
 * and getting reused
 * 
 * Remember: the stack is only memory safe within the context of the
 * current function!
 * 
 * Assignment: 
 *  1. Run the code as it is and I'll see something ... weird. Why
 *     don't the x and y values match the ones passed in on lines 
 *     51-53?  
 * 
 *      Because I'm accessing stack memory (the pointer created on
 *      line 40) outside the function that created it, the memory
 *      has been deallocated and is no longer safe to use. Technically
 *      the behavior is undefined, but it's LIKELY that in this 
 *      specific scenario I'm just seeing it get overwritten by the
 *      next function call (thus 50 and 60 always print)
 * 
 *      NOTE: the above is the result from Bootdev. but the version of
 *            C that i have won't even allow me to compile due to the
 *            dangling pointer
 * 
 *  2. Fix the new_coord function so that it returns a struct, not
 *     Not a pointer to a struct. This will force the compiler to
 *     copy the struct to the main function's stack frame, and the
 *     memory will be safe to use. I'll have to update syntax in
 *     a few places to make this change
 */
#include <stdio.h>

typedef struct {
    int x;
    int y;
} coord_t;

coord_t new_coord(int x, int y) {
    // coord_t *c;
    coord_t c = {
        .x=x,
        .y=y,
    };
    return c;  // this would be a dangling pointer because its created
    // in this function and when the function is popped off the stack
    // its memory is deallocated but the pointer to that memory remains
}

int main(int argc, char const *argv[])
{
    coord_t c1 = new_coord(10,20);
    coord_t c2 = new_coord(30,40);
    coord_t c3 = new_coord(50,60);

    printf("C1: %d, %d\n", c1.x, c1.y);
    printf("C2: %d, %d\n", c2.x, c2.y);
    printf("C3: %d, %d\n", c3.x, c3.y);
    return 0;
}
