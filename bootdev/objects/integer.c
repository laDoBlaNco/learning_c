/**Integer:
 *
 * I'll start simple with a single int object. The difference between a
 * 'snek integer' and a regular C int is taht the snek int:
 *      ▫️ Is allocated on the heap
 *      ▫️ Can store additional metadata about itself (for now just its type)
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/CA39zaZ.png
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

// an enum with a single value INTEGER
typedef enum
{
    INTEGER = 1,
} snek_object_kind_t;

// a union called snek_object_data_t with a single member, an integer named
// v_int
typedef union
{
    int v_int;
} snek_object_data_t;

// a struct declaration called snek_object_t with 2 members
//      ▫️ a member of type snek_object_kind_t named kind
//      ▫️ a member of type snek_object_data_t named data
typedef struct
{
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

// function declarations:
snek_object_t *new_snek_integer(int);

int main(int argc, char const *argv[])
{
    printf("\nTest 'test_positive':\n");
    snek_object_t *int_object1 = new_snek_integer(42);
    printf("Should allow positve numbers. Should be 42 and it is %d\n", int_object1->data.v_int);
    free(int_object1);

    printf("\nTest 'test_zero':\n");
    snek_object_t *int_object2 = new_snek_integer(0);
    printf("Must be int type and its type is %d\n", int_object2->kind);
    printf("Must equal zero and it is %d\n", int_object2->data.v_int);
    free(int_object2);

    printf("\nTest 'test_negative':\n");
    snek_object_t *int_object3 = new_snek_integer(-5);
    printf("Must be int type and its type is %d\n", int_object3->kind);
    printf("Must allow negative numbers. Should be -5 and it is %d\n", int_object3->data.v_int);

    return 0;
}

snek_object_t *new_snek_integer(int value)
{
    // allocate heap memory for a new ptr to a snek_object_t
    snek_object_t *ptr = malloc(sizeof(snek_object_t));
    // if allocation fails return NULL
    if (ptr == NULL)
    {
        return NULL;
    }
    // set the kind field of the new snek object to integer
    ptr->kind = INTEGER;
    // set the v_int field of the new object to the value passed in
    ptr->data.v_int = value;
    // return the pointer to the new snek object
    return ptr;
}
