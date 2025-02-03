/**
 * Unions: So I wonder if this is where the idea of "union types" that I've
 * heard of are coming from.
 * Unions are a field in the struct  that assigns multiple labels of multiple
 * types to the same memory location. So what does that mean?
 * 
 * We can create a structure with unions with the following syntax, meaning
 * putting various types in this field. 
 */
#include <stdio.h>

union myunion {
    int i;
    char c;
};
// creates a type call union myunion that we can use later on in the code.
// thus "union types". This structure ahs two members i and c, but both of them
// will contain data at the same location. The union is only the size of he largest
// element, so in this case int i, or 4 bytes. The fact that it creates enough room
// for the biggest element means that either of the elements can fit in that memory
// space. 

// what can I do with this in practice?
// 
// 

int main(int argc, char const *argv[])
{
    union myunion u;
    u.i = 0x41424344;
    printf("%c\n", u.c);
    return 0;
}



