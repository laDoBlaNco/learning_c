/**
 * Objects function, macros and other C identifiers have SCOPE that
 * delimits the contiguous regeion wherre they can be accessed. C has
 * 4 types of scope:
 *  - file -- object declared outside any block or param list. Meaning
 *    the scope is the entire file.
 *  - block -- object declared inside a block or param list, meaning
 *    that the identifier is accessible only in that block 
 *  - function prototype -- object declaration appears within the list of
 *    parameter declarations in a function prototype (not part of the function def)
 *    and terminates at the end of function declaration.
 *  - function -- is the area between the opening { of a function definition and its
 *    closing }. A label name is really the only type of identifier that has 
 *    function scope. Labels are identifiers followed by a colon and identify a
 *    statement in a function to which control may be transferred. We'll come
 *    back to this one later. 
 * 
 * The type of scope depends on where its declared as seen above
 */
#include <stdio.h>

int j; // this is file scope

void f(int i) // block scope of i begins here
{
    int j = 1; // block scope of j begins; hides file-scoped j
    i++;        // i refers to the function parameter
    for (int i=0;i<2;i++) { // block scope of loop-local i begins
        int j = 2;  // block scope of inner j begins; hides outer j
        printf("%d\n",j); // inner j is in scope, prints 2
    }                       // block scope of the inner i and j ends
    printf("%d\n",j);       // the outer j is in scope, prints 1
}                       // the block scope of i and j ends

void g(int j);  // this j has function prototype scope; hides file-scope j

int main(int argc, char const *argv[])
{
    f(66);
    return 0;
}

// There's nothing wrong with the code above as in it works, but best practice 
// is to use different var names to avoid confusion and bugs from variable hiding
// short names are fine for identifiers in small short scopes but otherwise they
// should be more descriptive and longer. 
