/**Floats:
 *
 * So i obviously need to add floats here, or how else will all the crypto bros
 * write weird floating-point bugs into their smart contracts?
 *
 * So how do i do that. How do I store both floats and ints into the same type?
 *
 * I'm going to use the union and enums I created before. just like I saw in
 * previous chapters. I'll need to extend the existing objects below to include
 * both ints and floats (and Ill continue to add mroe types to these obj in
 * following chapters)
 */
#include <stdio.h>
#include <stdlib.h>

// an enum with a single value INTEGER
// Add the new enum value for floats
typedef enum
{
    INTEGER = 1,
    FLOAT,
} snek_object_kind_t;

// a union called snek_object_data_t with a single member, an integer named
// v_int
// Add a new float field as v_float
typedef union
{
    int v_int;
    float v_float;
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
snek_object_t *new_snek_float(float);

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

    printf("\nTest 'test_positive_float':\n");
    snek_object_t *float_object1 = new_snek_float(42);
    printf("Should allow positve numbers. Should be 42 and it is %f\n", float_object1->data.v_float);
    free(float_object1);

    printf("\nTest 'test_zero_float':\n");
    snek_object_t *float_object2 = new_snek_float(0.0);
    printf("Must be float type and its type is %d\n", float_object2->kind);
    printf("Must equal zero and it is %f\n", float_object2->data.v_float);
    free(float_object2);

    printf("\nTest 'test_negativefloat':\n");
    snek_object_t *float_object3 = new_snek_float(-5.0);
    printf("Must be int type and its type is %d\n", float_object3->kind);
    printf("Must allow negative numbers. Should be -5 and it is %f\n", float_object3->data.v_float);

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

snek_object_t *new_snek_float(float value)
{
    // allocate memory for a new pointer to snek_object_t
    snek_object_t *ptr = malloc(sizeof(snek_object_t));
    // if allocation fails return NULL
    if (ptr == NULL)
    {
        return NULL;
    }
    // set the kind field to the appropriate enum
    ptr->kind = FLOAT;
    // store the float value in the object
    ptr->data.v_float = value;
    // return the pointer to the new object
    return ptr;

}
