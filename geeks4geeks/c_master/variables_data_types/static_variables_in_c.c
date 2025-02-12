/** Static Variabler in C
 * 
 * In C, static variables are the variables declared using the
 * 'static' keyword. These variables behaving differently compared
 * to normal or global variations. 
 * 
 * Properties of Static Variables
 * 
 * Following are the key properties of static variables in C: 
 * 1. Default Value
 *    If I left an uninitialized static variable, then it gets assigned
 *    a default value that depends on its type: 
 *      🔹 Static integer variables default to 0
 *      🔹 Character variables default to \0 (null character)
 *      🔹 Floating-point variables default to 0.0
 * 
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    static int x;

    printf("%d\n",x); // zero default just like Go, must be where they
    // got it from. 
    // This behavior makes them predictable compared to normal (non-static)
    // variables, which may hold garbage memory values if uninitialized.

    /**
     * 2. Static Variable Lifetime
     * Local variables in a function are created when the function is
     * called and destroyed when the function ends. However, if a local
     * variable is declared as static, its lifetime extends beyond the 
     * function's scope.
     * 
     * This means that the variable retains its value across multiple
     * function calls. It is initialized only once during the program's 
     * execution. 
     * 
     * 3. Static Global Variables: 
     * Normal global variables can be accessed from other files if they 
     * are linked appropriately, whereas static global variables have
     * internal linkage. Internal linkage refers to the scope of variables
     * that restricts their visibility to the current file only. 
     */
    return 0;
}

