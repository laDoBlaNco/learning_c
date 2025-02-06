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
 * really understand what's going on here. 
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
    // a string and its a DOUBLE pointer at the same time???

    // We are moving the address instead of dereferencing and moving
    // the value
    char *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    // Its the same as working with the integer. I'm letting the **
    // confuse me. Basically working with int *ptr same as with char **ptr
}

