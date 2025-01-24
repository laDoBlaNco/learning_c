#include <stdio.h>

/**Derived Types:
 * 
 * These are types that are constructed from other types. That's close to what I
 * determined previously. This includes, pointers, arrays, typedefs, structs, and 
 * unions.
 * 
 */

/**Pointer Types:
 * 
 * A pointer type is derived from the function or object type that it points to, 
 * which is called the reference type. A pointer provides a reference to an entity
 * of the referenced type.
 * 
 * Below we see 3 declarations of a pointer to int, a pointer to char, and a pointer
 * to void
 * 
 */
int *ip;
char *cp;
void *vp;

/**
 * In pevious parts of this book I saw the 'address-of' (&) and indirection (*) 
 * operators. These are the same pointer semantics used in most languages, such 
 * as Go.  I use & to take the addres of an object or function. If the object is
 * an int, for example, the result of the operator has the type pointer to int.
 */
int i = 17;
int *ip = &i;
// int *ip2 = &66; AS i THOUGHT YOU CAN'T POINT TO A CONSTANT APPARENTLY
// I can also use the & operator on the result of the * operator. Not sure why 
// I would want to do that, unless the address of the pointer is something I'm after
// and this will give me that 🤔
ip = &*ip;

// A bueno, nope, according to Seacord these two actions cancel each other out which
// makes sense. So not sure why I would ever do this, but maybe I'll see this kinda
// stupidity in the wild.

/**
 * The unary operator converts a pointer to a type into a value of that type. It 
 * denotes indirection and operates only on pointers. If the operand points to a 
 * function, the result of the * operator is the function designator and if it points 
 * to an object, the result is a value of the designated obj. IF THE POINTER IS NOT
 * POINTING TO A VALID OBJECT OR FUNCTION, BAD THINGS MAY HAPPEN.
 */


/**Arrays:
 * 
 * As seen before an array is a contiguously allocated sequence of objects that all
 * have the SAME element type. Array types are characterized by their elemnent types
 * and the number of elements in the array. Here I'm declaring an array of 11 elements
 * of type int and an array of 17 elements of type pointer to float
 * 
 */
int ia[11]; // int array size 11 elements
float *afp[17]; // float array size 17 pointers to float

// Square brackets identify for me the element of an array. For example, here is aa 
// contrived example creating the string '012345678'
void func(int arr[5]);


int main(int argc, char const *argv[])
{
    char str[11];
    for (unsigned int i = 0; i < 10; ++i) {
        str[i] = '0' + i;
    }

    str[10] = '\0';

    unsigned int i = 0;
    unsigned int j = 0;
    int arr[3][5];

    func(arr[i]); // we haven't defined this anywhere
    int x = arr[i][j];

    return 0;
}

/**
 * The first line declares the array of char with abound of 11??? This allocates
 * sufficient storage to create a string with 10 chars PLUS A NULL CHARACTER FOR THAT
 * PESKY BUFFER OVERFLOW ISSUE
 * 
 * Something interesting with working with arrays that I think bobbles up in many
 * languages, but I recognize it from Go. and that's why its a reference type
 * 
 * In the expression, 'str' is automatically converted to a pointer to the first
 * member of the array (an object of type char), and i has an unsigned int type.
 * Just like in Go this is actually str[i] = *(str + i). When str is an array object
 * teh expression str[i] designates the ith element of the array (counting from 0)
 * Because arrays are 0-indexed, the array char str[11] is indexed from 0 to 10 with
 * 10 being the last element
 * 
 * If the operand  of the unary & operator is the result of a [] operator, the 
 * result is as if the  & operator were removed and the [] operator were changed
 * to a + operator. &str[10] is the same as str + 10 since we are working with the
 * same contiguous block of memory maybe???
 * 
 * i can also declare multi-dimensional arrays which doesn't surprise me at all as
 * seen above in main
 * 
 * More precisely, arr is an array of three elements, each of which is an array
 * of five elements of type int. When I use the expression arr[i]  which again is
 * the same as *(arr + i), the following happens:
 *   1. arr is converted to a pointer to the intial array of five elements of type
 *      int starting at arr[i]
 *   2. i is scaled to the type of arr by multiplying i by the size of one array of
 *      five int objects.
 *   3. The result from steps 1 and 2 are added
 *   4. Indirection is applied to the result to produce an array of five elements of
 *      type int.
 */

/**TYPE DEFINITIONS
 * 
 * I use a typedef to declare an alias for an exisiting type; it NEVER creates
 * a new type. For example, each of the following declarations creates a new type
 * alias, not a new type
 *  - typedef unsigned int uint_type;
 *  - typedef signed char schar_type, *schar_p, (*fp)(voiid);
 * 
 * For some reason this reminds me a lot of Go structs behavior and semantics. 
 * 
 * On the first line I declare uint_type as an alias for the type unsigned int.
 * So instead of typing unsigned int everywhere I can just type uint_type. On the
 * second line I declare schar_type as an alias for signed char, schar_p as an 
 * alias for signed char *, and fp as an alias for signed char(*)(void). Identifiers
 * that end in '_t' in the standard headers are typedefs (aliases of exisiting types)
 * Generally speaking I shouldn't follow this convention for my own code cuz C reserves
 * identifiers that match the patters int[0-9a-z_]*_t and uint[0-9a-z_]*_t. If I 
 * define identifiers that use those names, they may collide later with names used
 * by an implementation, which would be my problem.
 * 
 */

/**Structures:
 * The struct type contains sequentially allocated member objects. Each object has
 * its own name and may have a distinct type (unlike arrays), which must all be the
 * same type. Structs rae similar to record types found in other programming languages
 * 
 * For example:
 */
struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
} sigline, *sigline_p;  // again seeing this which Teej intro'd to me

/**
 * This struct has 3 members: signum is an object of type int, signame is an array
 * of type char consisting of 20 elements, and sigdesc is an array of type char 
 * consisting of 100 elements.  
 * I'M NOT 100% CLEAR ON THAT ENDING SYNTAX THOUGH 🤔???
 * 
 * Structs are useful for declaring collections  of related objects and may be used
 * to represent things such as a date, customer, or personnel record. They are 
 * especially useful for grouping objects that are frequently passed together as 
 * args to a funtion, so I don't need to repeatedly pass individual objs separately.
 * 
 * Once I've defined a struture, I will need to reference it in the program. I do
 * this using the member (.) operator just like other languages. IF I HAVE A POINTER
 * TO A STRUCTURE, I CAN REFERENCE  ITS MEMBERS WITH THE STRUCT POINTER (->) (I think
 * that's where PHP got it from with its classes).
 */

// sigline.signum = 5;  // not sure why this is giving me an error so I'll put the
// rest of the doce in a comment block
/**
 * strcpy(sigline.signame = "SIGINT");
 * strcpy(sigline.sigdesc = "Interrupt from keyboard");
 * 
 * signline_p = &sigline;
 * 
 * sigline_p->signum = 5;
 * strcpy(sigline_p->signame,"SIGINT");
 * strcpy(sigline_p->sigdesc, "Interrupt from keyboard");
 * 
 * The first 3 lines access the members directly using . operator. In the final
 * 3 lines I inddirectly access the members of the sigline object by using ->
 * This brings up the question, are structs then copies or passed by reference???
 */


/**Unions:
 * 
 * So Union types are very similar to structs, except that the memory used by 
 * the objects OVERLAPS. Unions can contain an object of one type at one time, 
 * and an object of a different type at a different time, but never both objects
 * at the same time. they are primarily used to save memory, so great for embedded
 * coding. This sounds like the bases for Union Types in other languages which seems
 * more like generics.
 * 
 * The union below might be used in a tree, graph, or other data structure that 
 * has some nodes that contain integer values (ni) and other nodes that contain
 * floating-point values (nf)
 * 
 */
union {
    struct {
        int type;
    } n;
    struct {
        int type;
        int intnode;
    } ni;
    struct {
        int type;
        double doublenode;
    } nf;
} u;
// u.nf.type = 1;
// u.nf.doublenode = 3.14;
// more errors on these last two lines. I'll need to come back to unions and structs
// I think it has something to do with that naming convention or maybe cuz I'm outside
// of the main func obove.
// As with structs we access its members with . and -> . I'll probably use these when
// I get into DSA in C pretty soon.



