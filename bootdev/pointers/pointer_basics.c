/**Pointer Basics
 * 
 * Again Pointers are just variables with an address as its value
 * that tells the computer where to look for OTHRE VALUES. just like
 * how the address to my house is not actually my house, but POINTS
 * to my house
 * 
 * Syntax/Semantics Review:
 * We declare a pointer using the pointer type declaration which is
 * any type declaration with an *:
 * int *pointer_to_something; // declares 'pointer_to_something' as a
 * pointer-to-int
 * 
 * Get the address of a variable, thus creating the pointer you are 
 * going to put into the pointer variable with &
 *      int meaning_of_life = 42;
 *      int *pointer_to_mol = &meaning_of_life;
 * pointer_to_mol now holds address to meaning_of_life
 * 
 * Dereferencing Pointers:
 * A lot of times I'll want to get access to the data that my pointer
 * is pointing to, not just the address itself, but the value stored 
 * at that address. Well then I use the * again, but without the 
 * type name, to dereference or access the value of that pointer. Its
 * simply the pointer is REFERENCING a value so now with *, I'm 
 * DEREFERENCING that reference to get the value back. And just get
 * the value but TOUCHING THE ACTUAL VALUE IN MEMORY. 
 * 
 * It can get a bit confusing, but I just have to remember that the
 * * does two different things. 
 *      1. Declaring a pointer type: int *pointer_to_thing;
 *      2. Dereferencing a pointer value: *pointer_to_thing = 20 or
 *         int my_value = *pointer_to_thing;
 * 
 */

#include <stdio.h>

typedef struct CodeFile
{
    int lines;
    int filetype;
} codefile_t;

codefile_t change_filetype(codefile_t *, int);

int main(int argc, char const *argv[])
{
    int meaning_of_life = 42;
    int *pointer_to_mol = &meaning_of_life;
    int value_at_pointer = *pointer_to_mol;

    printf("The value AT (not from) Pointer To MOL = %d\n",value_at_pointer);
    printf("\n");
    //=======================================================
    // Assignment
    //=======================================================
    codefile_t file = {.lines=150,.filetype=1};
    codefile_t *pointer_to_file = &file;

    codefile_t updated = change_filetype(pointer_to_file,5);
    printf("Code File Struct:\n\t"
           "Lines: %d\n\t"
           "File Type: %d\n\n",updated.lines,updated.filetype);
    printf("Original Code File Struct:\n\t"
           "Lines: %d\n\t"
           "File Type: %d\n\n",file.lines,file.filetype);

    // here I want to experiment a little bit.  Are any part of
    // my struct a pointer? Do my struct and field addresses
    // coincide?
    printf("Code File struct address: %p\n",&file);
    printf("Code File field lines address: %p\n",&file.lines);
    printf("Code File field filetype address: %p\n",&file.filetype);
    // So the above tells me something. First that the name file is point
    // to the same memory address as the first field. So as mentioned 
    // earlier the struct is contiguous and starts with the first field
    // then 4 bytes later is the second field 
    // That also answers my other question I believe, but let
    // me try to see if the fields are pointers themselves:

    // printf("Code File field filetype ptr?: %p\n",file.filetype);
    // nope seems like they are not. So its clear that we are dealing
    // with continguous types/value in memory with the name of the
    // struct pointing to that first field. But I still have my
    // questions below


    return 0;
}

codefile_t change_filetype(codefile_t *f,int new_filetype)
{
    // so codefile_t f is already a pointer (address) so all I
    // need to do is dereference it
    codefile_t new_file = *f;
    new_file.filetype = new_filetype;

    return new_file;
    
}

// someting feels off. I'm getting the value from the pointer here, 
// but then I'm just using it, I'm not actually changing the value
// at memory??? 🤔 With a pointer, should I be able to simply do
// what I need and then look at that value from anywhere else in
// the program and see the changes??? Not return a new copy of it.

// But when I look at the original its not changed. so even with the 
// pointer we are getting the value, updating and returning it, but
// not changing it inline, so to speak. That's a bit strange from
// what I understood as to how pointers should work. I'll come back to
// this note later???
