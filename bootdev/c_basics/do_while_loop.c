/**Do While Loop
 * 
 * A do while loop in C is a control flow statement that allows
 * code to be executed repeatedly based ona given boolean condition
 * 
 * Unlike the while loop, the do while loop checks the condition after
 * executing the lop body, so the loop body is ALWAYS going to run at 
 * least once.
 * 
 * Syntax:
 * do
 * {
 *     // loop body
 * }
 * 
 * Parts of a do while loop
 *  1. Loop Body
 *      - The block of code that is executed before checking the
 *        condition, and then repeatedly as long as the condition
 *        is true
 *  2. Condition
 *      - Checked after each iteration
 *      - If true, execute the body again
 *      - if false, terminate the loop
 * 
 * Key Points:
 *  1. The do while loop guarantees that the loop body is executed
 *     at least once, even if th condition is false initially
 *  2. The most common scenario I'll see a do-while loop used is in
 *     C macros - they let me define a block of code and execute it
 *     exactly once in a way that is safe across different compilers
 *     and ensures that the variables created/referenced within the
 *     macro doesn't leak to the surrounding environment.
 *  3. If I end up looking at any source code for macros, I'll probably
 *     see a few do-while loops. For example here's a simplified version
 *     from a testing library:
 * 
 * #define munit_assert_type_full(T, fmt, a, op, b, msg)
 *      do
 *      {
 *          T munit_tmp_a_ = (a);
 *          T munit_tmp_b_ = (b);
 *          if (!(munit_tmp_a_ op munit_tmp_b_))
 *          {
 *              munit_errorf("assertion failed: %s %s %s (" prefix "%" fmt suffix
 *                           " %s " "%" fmt "): %s",
 *                          #a, #op, #b, munit_tmp_a_, #op, munit_tmp_b_, msg);
 *          }
 *      } while (0) // this 0 is making sure this only runs once. 🤓
 * 
 * Some examples
 */
#include <stdio.h>

void print_numbers_reverse(int,int);

int main(int argc, char const *argv[])
{
    int i = 0;
    do
    {
        printf("i = %d\n",i);
        i++;
    } while (i <5 );
    printf("\n");

    print_numbers_reverse(70,60);
    
    return 0;
}

void print_numbers_reverse(int start, int end){
    do
    {
        printf("%d\n",start);
        start--;
    } while (start >= end);
    
}


