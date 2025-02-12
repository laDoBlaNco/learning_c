/**Scope of Variables in C
 * 
 * Scope = Lifetime
 * 
 * The area under which a variable is applicable
 * 
 * Strict  definition: A block or a region where a variable is declared
 * defined and used and when a block or a region ends, variable is
 * automatically destroyed (freed)
 */

#include <stdio.h>

int global = 5;

// global variable accessed from inside a function
void display()
{
    printf("%d\n",global);
}

// Function prototype scopes examples:
// (not part of the function definition) 
int Sub(int num1, int num2);

// file scope
int num1;

int main(int argc, char const *argv[])
{
    
    int var = 34; // scope of this variableis within main() function
                  // only. Therefore called 'local to main() func'
    printf("%d\n",var);

    /**
     * Scope of an identifier is the part of the program where the 
     * identifier may directly be accessible. In C, all identifiers
     * are lexically (or statically) scoped. C scope rules can be
     * covered under the following two catgories. 
     *  Basically 4 scope rules:
     *      ▫️ File scope - Scope of a identifier starts at the beginning
     *        of the file and ends at the end of the file. It referes to
     *        only those identfiers that are declared outside of all 
     *        functions. The identifiers of File scope are visible all
     *        over the file. Identifiers having file scope are global
     *      ▫️ Block Scope - Scope of a identifier begins at the opening
     *        '{' and ends at the ending '}'. Identifiers with block 
     *        scope are local to their block. 
     *      ▫️ Function Prototype Scope - Identifiers declared in function
     *        prototype are visible within the prototype
     *      ▫️ Function Scope - Function scope begins at the opening of 
     *        the function and ends with the closing of it. Function
     *        scope is applicable to labels only. A label declared is
     *        used as a target to goto statement and both goto and
     *        label statement must be in the same function
     * 
     *  1. File Scope
     *     These variables are usually declared outside of all of the 
     *     functions and blocks, at the top of the program and can be
     *     accessed from any portion of the program. These are also
     *     called the global scope variables as they can be globally
     *     accessed.  
     */

    printf("Before change within main: \n");
    display();

    // changing value of global variable from main function
    printf("After change within main: \n");
    global = 10;
    display();

    // If we declare a global variable in another file, we an access
    // it in that same file from anywhere. And in a second file if
    // we use the keyword 'extern' we an continue to use and access
    // the variable, though it was declared in an external file.

    // NOTE: To restrict access to the current file only, global variables
    // can be marked as 'static'

    /**
     * 2. Block Scope
     * A block is a set of statements enclosed within left and right braces {}
     * respectively. Blocks may be nested in C (a block may contain other blocks
     * inside it). A variable declared inside a block is accessible in the
     * block and all inner blocks of that block, but not accessible outside 
     * the block. Basically these are local to the blocks in which the variables
     * are defined and are not accessible outside. 
     */

    {
        int x = 10, y = 20;
        {
            // The outer block contains declaration of x and y, so 
            // following statement is valid and prints 10 and 20
            printf("x = %d, y = %d\n", x, y);
            {
                // y is declared again, so outer block y is shadowed
                // and not accessible in this block
                int y = 40;

                // This changes the outer block variable to 11
                x++;

                // this changes this block's variable y to 41
                y++;

                printf("x = %d, y = %d\n",x,y);
            }
            // This statement accesses only outer block's variables
            printf("x = %d, y = %d\n",x,y);
        }
    }

    /**
     * 3. Function Prototype Scope: 
     * These variables range includes within the function parameter list. 
     * The scope of these variables begins right after the declaration
     * in the function prototype and runs to the end of the declarations
     * list. These scopes don't include the function definition, but just
     * the function prototype. 
     */

    printf("%d \n", Sub(10,5));

    /**
     * 4. Function Scope: A function scope begins at the opening of the
     * function and ends with the closing of it. Function scope is 
     * applicable to labels only. A label declared is used as a target
     * to go to the statement and both goto and label statement must
     * be in the same function.
     */

    /**
     * What if the inner block itself has one variable with the same name?
     * If an inner block declares a variable with the same name as the
     * variable declared by the outer block, then the visiblity of the
     * outer block variable ends at the point of the declaration by
     * inner block (shadowed). 
     * 
     * What about functions and parameters passed to functions?
     * A function itself is a block. Parameters and other local variables
     * of a function follow the same block scope. 
     * 
     * Can variables of the block be accessed in another subsequent block?
     * No, a variable declared in a block can only be accessed inside 
     * the block and all inner blocks of that block. 
     */

    int a = 1, b = 2, c = 3;

    printf("a = %d, b = %d, c = %d\n",a,b,c);
    {
        int a = 10;
        float b = 20;
        printf("a = %d, b = %f, c = %d\n",a,b,c);
        {
            // changing c
            int c = 100;
            printf("a = %d, b = %f, c = %d\n",a,b,c);
        }
    }

    return 0;
}

// function to subtract
int Sub(int num1, int num2)
{
    return num1-num2;
}
