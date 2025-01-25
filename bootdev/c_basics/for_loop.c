/**For Loop
 * 
 * A for loop in C is a control flow statement for repeated execution
 * just like any other language. Very similar ot py, but with the 
 * classic syntax. 
 * 
 * The syntax of a for loop in C consists of three main parts:
 * 1. Initialization
 * 2. condition
 * 3. final-expression
 * 
 * There is no 'for each' 'for..in' 'for..of' etc in C. Remember we are
 * on the metal with C. So we used the indexs to iterate over the 
 * numbers. Add this to what I learned about how arrays are just pointers
 * using pointer arithmetic and it 🤯🤯🤯🤯🤯
 * 
 * for (initialization;condition;final-expression) {}
 * 
 * Parts of a For Loop:
 *  1. Initialization
 *      - Executed only once at the beginning of the loop
 *      - Is typically used to initialize the loop counter: int i=0;
 *  2. Condition
 *      - Checked before each iteration
 *      - If true, execute the body, if false, terminate the loop
 *      - Often checks to ensure i is less than some value: i < 5; 
 *  3. Final-Expression
 *      - Executed after each iteration of the loop body
 *      - Can be used to update the loop counter or run any other code
 *        i++ for example. NOTE: you can run any other code as well
 *  4. Loop Body
 *      - The block of code that is executed while the condition is
 *        true
 * 
 * Couple of examples
 */

#include <stdio.h>

void print_numbers(int,int);

int main(int argc, char const *argv[])
{
    for (int i=0;i<5;i++){
        printf("%d\n",i);
    }
    printf("\n");

    print_numbers(60,70);

    return 0;
}

void print_numbers(int start,int end)
{
    for (int i = start; i <= end; i++)
    {
        printf("%d\n",i);
    }
}

