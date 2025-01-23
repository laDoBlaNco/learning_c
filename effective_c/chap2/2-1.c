#include <stdio.h>

/**
 * The first thing to learn n this chapter is one of the last 
 * things a lot of C devs learn and that's that EVERY TYPE IN C
 * IS EITHER AN OBJECT TYPE OR A FUNCTION TYPE. what does that mean?
 * 
 * An objet is storage in which you can rep values. To be precise, an
 * object is defined by the C standard as a "region of data storage
 * in the execution env, the contents of which can represent values",
 * with the added note, "when referenced, an object can be interpreted as
 * having a particular type"
 * 
 * A variable is an example of an object. They have a declared type that
 * tells us the kind of object it is.
 * 
 * The tyep is important cuz the collection of bits that represent one
 * type of object will likely be a different value if interpreted as a different
 * type of object. As aa great example, the number 1 is rep'd in IEEE 754 (floats)
 * by the bit pattern 0x3f800000 and that's a 1, but if we were to interpret this
 * same bit pattern as an int, we would get 1,065,353,216 isntead of 1 🤯, That's a
 * shockingly big difference. 
 * 
 * Functions are not objects but they do have types. A function type is 
 * characterized by both its return type as well as the number of types of its 
 * parameters. 
 * 
 * There are also pointers, which can be thought of as an address to a location
 * in memory where an object or function is stored. A pointer's type is derived
 * from a function or object type called a reference type. A pointer type derived
 * from the referenced type T is called a pointer to T.
 * 
 * Because objects and functions are different things, object pointers and 
 * function pointers are also different things, and should not be used 
 * interchangeably. In the following sections we'll write a simple program that
 * attempts to swap the values of two variables to get a better understanding
 * of objects, functions, pointers, and types.
 */

// here we declare the function swap, but its defined below
void swap(int,int);
void swap2(int *,int *);

int main(void)
{
    int a = 21;
    int b = 17;

    swap(a,b);
    swap2(&a,&b);
    printf("main: a = %d, b = %d\n",a,b);
    return 0;
}

// here the swap function is defined.
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    printf("swap: a = %d, b = %d\n",a,b);
}

/**
 * Each object has a STORAGE DURATION that determines its lifetime
 * which is the time during program execution for which the object 
 * exists, has storage, has a constant address, and retains its last-stored
 * value. Objects must not be referenced outside their lifetime. 
 * 
 * Local vars, such as a,b above have AUTOMATIC STORAGE DURATION meaning
 * they exist until execution leaves the block where they are defined. 
 * 
 * the results of this first implementation are surprising because
 * we can see from the call that the swapping took place, but the last
 * printf() shows them unchanged. This is because C is a call-by-value or
 * pass-by-value language which as we know means that we work with copies.
 * 
 * That's why everything is done in the function but when the function ends
 * the changes aren't sustained. 
 * 
 * let's try again:
 */

void swap2(int *pa, int *pb)
{
    // using pointer semantics, this reminds me of what I learned from
    // studying Go
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return; // no need to print or return a result since we are changing
    // the original values with pointers
}

/**
 * Here in swap2 we use the INDIRECTION (*) operator which is part of the
 * pointer semantics to both declare pointers and dereference them. 
 * When in a function declaration or definition, * acts as part of a pointer
 * declarator indicating that the parameter is a pointer to an object or function
 * of a specific type (int *pa, int *pb). We use the * unary operator in expressions
 * the unary operator dereferences the pointer to the object. so there is a diff
 * here:
 * pa = pb; This replaces the value of the pointer pa with teh value of the pointer
 * pb, but that's just the pointer value
 * *pa = *pb;  This dereferences the pointer pb, reads the referenced value, dereferences
 * the pointer pa, and then overwrites the value at the location referenced by pa
 * with the value referenced by pb. EXACTLY WHAT i LEARNED WHILE STUDY GO POINTERS
 * 
 * When we call the swap function in main, we must also place an (&) char before 
 * each argument:
 * swap(&a, &b); 
 * The unary & is the ADDRESS-OF operator, which generates a pointer to its 
 * operand. This change is necessary because the swap function now accepts pointers
 * to objects of t ype int as params instead of simply values of type int. 
 * 
 * In end we are mimicking call-by-reference (pass-by-reference) with this approach.
 * Since the code takes the addresses of tehse objects and passes them to the swap2
 * function as args. Within the swap2 function, the params pa and pb now both declared
 * to have the type POINTER TO INT and contain COPIES of the arguments passed. These
 * address copies STILL refer to the exact same objects, so when the values of the
 * objects in the swap2 function are accessed and swapped, the original objects in 
 * main are accessed and also swapped. By generating object addresses, passing those
 * by value, and then dereferencing  the copied addresses to acces the original objects
 * we are creating the pass-by-reference result
 * 
 * 
 */