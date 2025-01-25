/**C is Compiled:
 * 
 * As seen before python code works from top to bottom so the following
 * code would print starting and then flake out when it hits the runtime error
 * 
 * python:
 * 
 * print("starting")
 * func_that_doesnt_exist("uh oh")
 * print("finished")
 * 
 * but in C this would crash before it can even run. If there's a problem
 * the compiler tells us before the program even starts. Now...C doesn't 
 * tell us about ALL the possible problems (skill issues) that might arise
 * in our program, but it does tell us about some of them.
 * 
 * 
 * 
 */

// Fix the bug
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("starting sneklang tools\n");
    // does_not_exist("uh oh");
    printf("finished sneklang tools\n");
    return 0;
}
