/**Sizeof:
 * 
 * As already seen C gives us a way of checking the size of a type 
 * or a var with sizeof.
 * 
 * I can use sizeof like a function or like the unary operator it
 * is sometimes. In this course I'll sue sizeof to get some insight into the 
 * memory layout of different types in C. This will be particulary 
 * useful as we move deeper into C, and essential for understanding
 * pointers. 
 * 
 * size_t
 * The size_t type is a special type that is guaranteed to be able to
 * represent the size of the largets possible object in the target 
 * platforms address space (i.e. can fit any single, non-struct value
 * inside of it) Its also the type that is returned from sizeof. This 
 * is why earlier in a different program when I tried to print the 'sizeof'
 * as an integer, although it was just 1, I had to use %ld instead of %d
 * for %longdigit or long integers 🤯 and according to the following 
 * https://stackoverflow.com/questions/32037237/why-do-i-have-to-use-ld-when-referring-to-the-size-of-an-int-variable
 * 
 * i should really use %zu. %z is the format specifier that says another
 * modifier will be following that will convert this to use with size_t 
 * specifically. In this case zu for unsigned
 * 
 * Below I'll use %zu for this
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    // use %zu for printing 'sizeof' results - I didn't know what
    // that meant before when I saw it.
    printf("sizeof char = %zu\n",sizeof(char));
    printf("sizeof bool = %zu\n",sizeof(bool));
    printf("sizeof int = %zu\n",sizeof(int));
    printf("sizeof float = %zu\n",sizeof(float));
    printf("sizeof double = %zu\n",sizeof(double));
    printf("sizeof size_t = %zu\n",sizeof(size_t));
    return 0;
}
