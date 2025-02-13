/**Swap the Numbers (again)
 * 
 * Given 2 numbers a and b, I need to swap their values so a holds
 * the value of b and b holds the value of a. 
 */
#include <stdio.h>

 void swap(int *a, int*b)
 {
    int temp = *a;
    *a = *b;
    *b = temp;
 }

 int main(int argc, char const *argv[])
 {
    int a = 66, b = 69;
    printf("%d %d\n",a,b);
    swap(&a,&b);
    printf("%d %d\n",a,b);

    return 0;
 }
 