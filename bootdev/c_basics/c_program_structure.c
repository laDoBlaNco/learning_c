/**C Program Structure
 * 
 * The python intrepreter executes from top to bottom. When it hits a 
 * function like print() it will then do that. The entire file is 
 * INTERPRETED line by line, but that's not how C works.
 * 
 * SIMPLEST C PROGRAM:
 * 
 * int main(){
 *      return 0;
 * }
 * 
 * This is the simplest C program doesn't do anything but there is a 
 * lot happening here:
 *  - A function named main is awlays the entry point for C programs
 *    (unlike Python which just starts at the top)
 *  - 'int' is the return type of the function and is short for 'integer'
 *    Because this is the main function, the return value is the 'exit code'
 *    of teh program. 0 means success and anything else means failure.
 *    - There are lots of abbreviations in C because 
 *       1. programmers are lazy
 *       2. it used to matter how many bytes your source code was
 *  - The opening bracket, { is the start of teh funtion's body (C
 *    ignores white space, so indentation is just for style, not for
 *    syntax)
 *  - 'return 0' returns the 0 value (an int) from the function. 
 *    Again, this is the exit code becasue it's the main function
 *      - 0 represents "nothing bad happened" as a return value
 *  - The pesky ';' at the end of 'return 0;' is required in C to
 *    terminate statements
 *  - The closing bracket '}' denotes the end of the function's body
 * 
 * PRINT:
 * It feels very different coming from python, but print in C is 
 * done with a function called printf from the stdio.h (standard input/output)
 * library with a lot of weird formatting rules. To use it, you need 
 * an #include at the toe of the file. or before the code as below
 * 
 * Then I can use printf from inside a function or the main function
 * as below. Note the '\n' it's required to print a newline char (and
 * flush the buffer in the browser), which print() in py does automatically
 * 
 * The 'f' stands for 'formatted'
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Hello, C Hackers!\n");
    return 0;
}
