/**Type Qualifiers:
 * 
 * All the types examined so far here have been UNQUALIFIED types. 
 * Types can be qualified by using one or mroe of the following qualifiers:
 *      - const
 *      - volatile
 *      - restrict
 * This is new! 🤔
 * 
 * Each of these qualifiers changes behaviors when accessing objects
 * of the qualified type. So even more like an OOP set up. 🤔
 * 
 * The qualified and unqualified versions of types can be used interchangeably
 * as arguments to functions, return values from functions, and members 
 * of uniones. Actually I saw an example of a qualified type in bootdev
 * earlier today as well. A return type and an arg using const before the 
 * type. 'const char *'
 * 
 * CONST:
 * Objects declared with the const qualifier (const-qualified types) are
 * not modifiable. In particular, they're not assignable but can have 
 * constant initializers. This means objects with const-qualified types
 * can be placed in ro memory by the compiler, and any attempt to write 
 * to them will result in a runtim error.
 * 
 *      const int i = 1; // const-qualified int
 *      i = 2 // error: i is const-qualified.
 * 
 * It is possible to accidentally convince my compiler to change a
 * const for me. In the following example, I take the address of a
 * const-qualified object i and tell the compiler that this is actually
 * a pointer to an int:
 *      const int i = 1; // object of const-qualified type
 *      int *ip = (int *)&i;
 *      *ip = 2;  // the compiler will allow the constant to be changed. 
 * So we are basically casting a pointer to a pointer
 * 
 * C doesn't allow me to cast away the const if the original was declared 
 * as a const-qualified object. Thsi code might appear to work, but its 
 * defective and may fail later. For example, the compiler might place the
 * const-qualified object in ro memory, causing a memory fault when trying
 * to store a value in the object at runtime, causing a runtime bug.
 * 
 * C allows me to  modify an object that is pointed to by a const-qualified 
 * pointer by casting the const away, provided that the original object was
 * declared const:
 *      int i = 12;
 *      const  int j = 12;
 *      const int *ip = &i;
 *      const int *jp = &j;
 *      *(int *)ip = 42; // will be ok since the original i wasn't const
 *      *(int *)jp = 42; // will be a bug or undefined behavior.
 * 
 * 
 * VOLATILE:
 * Objects of volatile-qualified types serve a special purpose. Static 
 * volatile qualified objects are used to model memory-mapped input/output
 * ports and static constant volatile-qualified objects model memory-mapped
 * input ports such as real-time clock.
 * 
 * The values stored in these objects may change without the knowledge of 
 * the compiler. For example, every time the value from a real-time clock
 * is read, may change, even if the value has not been written to by the
 * C program. Using a volatile-qualified type lets the compiler know the value
 * may change and ensures that every access to the real-time clock occurs
 * (otherwise an access to the real-time clock may be optimized away or 
 * replaced by a previously read and cached value). In the following code
 * for exaample, the compiler must generate instructions to read the value
 * from port and then write this value back to port:
 * 
 *      volatile int port;  // tells the compiler this might change so
 *      port = port; // read from port and write back to port
 * 
 * Now without the volatile qualification, the compiler might see this 
 * instruction as a no-op (a programming instruction that does nothing) 
 * and ptentially eliminate or optimize it away. 
 * 
 * Also, volatile-qualified types are used for communication with signal
 * handlers and with setjmp/longjmp (assembly instructions) (refer to the
 * C standard for information on handlers and setjmp/longjmp). Unlike Java
 * and other programming languages, volatile-qualified types in C should
 * not be used for synchronization between threads.
 * 
 * RESTRICT:
 * A restict-qualified pointer is used to promote optimzation. Objects
 * indirectly accessed through a pointer frequently can't be fully optimized
 * because of potential aliasing, which occurs hen more than one pointer refers
 * to the same object. Aliasing can inhibit optimizations, because the compiler
 * can't tell if portions of an object can change values when another apaprently
 * unrelated object is modified, for example.
 * 
 * The following function copies n bytes from the storage referenced by
 * q to the storage referenced by p. The function params p and q are both 
 * restrict-qualified pointers. 
 * 
 * void f(unsigned int n, int *restrict p, int *restrict q) {
 *      while (n-- > 0) {
 *          *p++ = *q++;
 *      }
 * } 
 * 
 * Because both p and q are restrict-qualified pointers, the compiler 
 * can assume that an object acessed through one of the pointer params
 * is not also accessed through the other. The compiler can make this
 * assessment based solely on the parameter declarations without 
 * analyzing the function body. Although using restrict-qualified pointers
 * can result in more efficient code, i must ensure that the pointers do
 * not refer to overlapping memory to preven undefined behavior 
 * 
 * 
 * 
 */

#include <stdio.h>

void increment(void);
unsigned int get_counter(void);

int main(int argc, char const *argv[])
{
    // exercises
    // 1. Add a retrieve function to the counting example from 2-6
    //    to retrieve the current value of counter.
    for (int i=0;i<5;i++) {
        increment();
    }
    printf("\n");
    printf("%d\n",get_counter());

    // 2. Declare an array of three pointers to functions and invoke
    //    the appropriate function based on an index value passed in
    //    as an argument.


    return 0;
}

void increment(void) {
    static unsigned int counter = 0;
    counter++;
    printf("%d ",counter);
}

unsigned int get_counter() {
    return __COUNTER__; // this is the static variable syntact or how
    // we refer to globals? I'll need to come back to this one.
    // didn't work
}
