/** Global Variables and Scope in C
 * 
 * In the C programming language, scope is the region of the program
 * where a given variable can be accessed using its name. Each variable
 * has a particular scope attached to it
 * 
 * On the basis of scope, there are two types of variables: 
 *      ▫️ Local Variables
 *      ▫️ Global Variables
 * 
 * Local Variables: 
 * These are the variables declared inside a function or block {} and
 * accessible only within the function or block {} where they are
 * defined. These variables are specific to the function or block. 
 * 
 * When a local variable is declared and not initialized, it may hold 
 * a random value (garbage memory)
 * 
 * Example:
 */

#include <stdio.h>

int y = 10; // this is global variable. What's the default? 0
extern int a;

int main(int argc, char const *argv[])
{
    int x = 10; // Local variable
    printf("%d \n",x);

    /**Global Variables
     * Global variables are declared outside all functions, usually
     * at the top of the program and accessible across the entire
     * program including all the functions. 
     * 
     * If a global variable is not initialized, it is automatically
     * assigned a default value of 0. This holds true for integers,
     * characters, and floating-point types. 
     */
    int z;  // local variable isn't set to a default???
    printf("%d \n",y);
    printf("%d \n",z);

    /** Extern Keyword and Global Variables
     * 
     * Global variables can be used before their definition by using
     * the 'extern' keyword. This tells the compiler that the variable
     * will be defined elsewhere. 
     */
    printf("%d \n",a);

    /**Variable Shadowing
     * A variable declared in an inner block or scope can shadow a 
     * variable with the same name from an outer scope. When a variable
     * is accessed, the innermost scope is checked first. If the
     * variable is not found, the compiler checks outer scope until
     * it finds a match. 
     * 
     * Two such cases are: 
     *      1. When local and global variable have same name. 
     *      2. When we have same variable name in multiple scopes. 
     */
    int y = 5;
    printf("%d \n",y);

    // Same name in multiple scopes
    int m = 75;
    {
        int m = 95;
        printf("%d \n",m);
    }
        printf("%d \n",m);

    return 0;
}

int a = 66;
