/**Swapping Strings
 * 
 * Let me take it up a notch (ok a half-notch, but still)
 * 
 * Assignment: 
 * Complete the swap_strings function. It swaps the values stored
 * in the string pointers. 
 * 
 *      ▫️ Remember that char** is a pointer to a char pointer,
 *        which means I can simply switch the 'address' that I'm
 *        referencing in the swap function.
 * 
 * This is one of the ones that keeps confusing me, so I need to 
 * really understand what's going on here. The key is going to be
 * not freaking out over the "double pointers" o sea the **. Its still
 * the same process just from a different level
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void swap_strings(char **, char **);

int main(int argc, char const *argv[])
{
    char *a = "Hello";
    char *b = "Goodbye";

    printf("\nTest #1\n");
    printf("A is currently %s\n",a);
    printf("B is currently %s\n",b);
    swap_strings(&a, &b);
    printf("A is now %s\n",a);
    printf("B is now %s\n",b);

    a = "terminal.shop";
    b = "ssh";

    printf("\nTest #2\n");
    printf("A is currently %s\n",a);
    printf("B is currently %s\n",b);
    swap_strings(&a, &b);
    printf("A is now %s\n",a);
    printf("B is now %s\n",b);


    return 0;
}

void swap_strings(char **a, char **b) {
    // I need to keep in mind that since 'char *' is a string and
    // its a pointer to an array, then 'char **' is a pointer to
    // a string which is technically a double pointer since 
    // char *a is just an address pointing to the character so in 
    // turn char **a is just an address of an address pointing to
    // a char. So...

    // We are dereferencing to the address instead of dereferencing and moving
    // the value
    char *tmp; // this has *tmp because its two pointers deep and we 
    // need to dereference to make it 1 pointer deep so its the same
    // as what we did with swapping the integers.
    tmp = *a;
    *a = *b;
    *b = tmp;

    // Its the same as working with the integer. I'm letting the **
    // confuse me. Basically working with int *ptr same as with char **ptr
    // but since the actual value (char) is TWO POINTERS DEEP then we 
    // need to dereference one of them to get to the same point I was
    // as when working with int *ptr. So again rather than swapping 
    // the value which would have to be: 
    //      **a = **b;
    //      **b = *tmp;
    // We are just swapping the address -- one pointer down -- :
    //      *a = *b;
    //      *b = tmp;
}

