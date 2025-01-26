/**Pointers to Structs
 * 
 * As I've learned before, when I have a struct I access the fields
 * with the dot (.) operator
 * 
 * Hovever when I'm working with a pointer to a struct, then I need 
 * to sue the arrow  -> operator
 * 
 * In effect it basically dereferences the pointer and accesses the field 
 * in one step. This is very much what is done in Go with some of the
 * syntactic sugar around pointers and structs which they probably 
 * got from here.
 * We can also use the *. combo but with some more characters and more
 * verbose
 * 
 * The . operator has a higher precedence than the * operator, so for
 * that reason I need ()s to make sure that the dereferencing happens
 * before accessing the field/member...which is another reason why
 * the arrow operator is so much more common.
 */

#include <stdio.h>

typedef struct Coordinate
{
    int x;
    int y;
    int z;
} coord_t;

int main(int argc, char const *argv[])
{
    coord_t point = {.x=15,.y=30,.z=45};
    coord_t *ptr_to_point = &point;

    printf("X: %d\n",point.x);
    printf("X: %d\n",ptr_to_point->x);
    printf("X: %d\n",(*ptr_to_point).x);


    return 0;
}

