#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Swap Two Numbers

    Given two numbers a and b, the task is to swap their values with each
    other.

        Input: a = 2, b = 3
        Output: a = 3, b = 2

        Input: a = "geeks", b = "for"
        Output: a = "for", b = "geeks"

    Approach:

    Let's consider the common idea most people think of which is simple
    assign a to b and b to a.

    This doesn't work because it makes both variables identical in the
    first assignment only. When I assign value of a to b, I'm lose the
    original value of a, resulting in both variables being the same value.

    The correct approach would be using a temp variable:
        1. Create a temporary var.
        2. Store the value of a in temp.
        3. Assign the value of b to a.
        4. Assign the value of temp to b.*/

    int a, b;
    scanf("%d %d", &a, &b);

    printf("Value of a is %d\n",a);
    printf("Value of b is %d\n",b);
    
    int temp = a;
    a = b;
    b = temp;

    printf("Value of a is %d\n",a);
    printf("Value of b is %d\n",b);

    return 0;
}
