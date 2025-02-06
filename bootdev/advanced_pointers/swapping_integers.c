/**Swapping Integers
 * 
 * Here I will practice pointers by swapping two values
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void swap_ints(int*,int*);

int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 6;

    printf("\nTest #1\n");
    printf("A is %d and B is %d\n", a,b);
    swap_ints(&a, &b);
    printf("A is now %d and B is now %d\n", a,b);

    printf("\nTest #2\n");
    a = 5;
    printf("A is %d\n",a);
    swap_ints(&a,&a);
    printf("A is still %d\n",a);

    return 0;
}

void swap_ints(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


