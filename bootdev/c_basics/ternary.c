/**Ternary Operator
 * 
 * Like JS, C has a ternary operator as well
 * 
 * The entire line is a single expression that evaluates to one value.
 *  - a>b is the condition
 *  - a is the final value if the condition is true
 *  - b is the final value if the condition is false
 *  - The entire expression (a>b?a:b) evaluates to either a or b
 *    which is then assigned to max in our example.
 * 
 * Ternaries are a way to write a simple if/else statement in one line.
 * 
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 10;
    int max = a > b ? a : b;
    printf("max: %d\n",max);
    return 0;
}


