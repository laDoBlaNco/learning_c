/**While Loop
 * 
 * A while loop in C is again just like and probably the grandaddy
 * of all the rest of the languages. Its a control flow statement
 * that allows code to be executed repeatedly based on a given bool
 * result (true/false) condition. The loop continues to execute as
 * long as the condition remains true.
 * 
 * Syntax:
 *  while (condition)
 * {
 *    // loop body
 * }
 * 
 * Parts of a while Loop
 *  1. Condition
 *      - Checked before each iteration
 *      - If true, execute the body. If false, terminate the loop
 *  2. Loop Body
 *      - The block of code that is executed while condition is true.
 * 
 * Key Points:
 *  - The condition is evaluated BEFORE the execution of the loop body
 *  - If the condition is false initially, the loop body will never
 *    even start
 *  - If the condition never becomes false, I'll get an infinite loop
 * 
 * Some examples:
 */
#include <stdio.h>

void print_numbers_reverse(int,int);

int main(int argc, char const *argv[])
{
    // our own counter initialized outside the loop
    int i = 0; 
    while (i < 5)
    {
        printf("%d\n",i);
        // make sure we manage our counter to avoid infinite loops
        i++; 
    }

    printf("\n");

    print_numbers_reverse(70,60);

    
    return 0;
}

void print_numbers_reverse(int start, int end)
{
    int i = start;
    while (i > end)
    {
        printf("%d\n",i);
        i--;
    }
    
}