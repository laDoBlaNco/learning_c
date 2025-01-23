#include <stdio.h>

/**
 * Storage Duration:
 * There are altogether 4 storage durations available:
 *  - automatic
 *  - static
 *  - thread 
 *  - allocated
 * 
 * Objects of automatic storage duration are declared within a block
 * or as a function parameter. The lifetime of these objects begins when
 * the block in which they're declared begins execution, and ends when
 * execution of the block ends. If the block is entered recursively, a 
 * new object is created each time, each with its own storage. This is why
 * recursion impacts space complexity quickly.
 * 
 * NOTE: ***Scope and lifetime are entirely different concepts. Scope applies
 * to identifiers, whereas lifetime applies to actual objects. The scope of an
 * identifier is the code region where the object denoted by the identifier can
 * be accessed by its name. The lifetime of the object is the time period for
 * which the object exists. ***
 * 
 * 1. Objects delcared in file scope have static duration. The lifetime of these
 *    objects is the entire execution of the program, and their stored value
 *    is initialized prior to program startup. -- We can use the storage-class
 *    specifier 'static' to declare a variable in block scope to have static duration
 * 
 */

void increment(void)
{
    static unsigned int counter = 0;
    // so this static does here where I've learned in OOP that static does
    // in a class. We are in block scope, but declaring it static we are giving
    // life for the entire program as if it were file scope. 🤯🤯🤯 Retaining
    // its last-stored value for the life of the program. Static objects must be
    // initialized with a constant value and not a var. 

    // constant value refers to a LITERAL CONSTANT (for example 1, 'a', 0xFF), 
    // enum members, and the results of operators such as  alignof or sizeof;
    // not const objects like 'const int j'

    counter++;
    printf("%d ",counter);
}

int main(int argc, char const *argv[])
{
    for (int i=0;i<5;i++){
        increment();
    }
    printf("\n");
    return 0;
}

// Thread storage duration is used in concurrent programming and is not 
// covered in this book, but I think in my Low-Level course as well as 
// the freecodecamp course I'll touch on those. 
