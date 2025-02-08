/**Vector3:
 *
 * So this is something new for me. Here I'll make an object that can hold
 * a reference to another object. Its a collection type, a type that holds
 * other types 🤯
 *
 * Arays, lists, dictionaries, and sets are all examples of collection types.
 * I won't implement all of these types in this course, but they each follow
 * the same pattern and I'll see here. And in another course I'm doing on C
 * data structures, I'll probably see a lot fo them there as well. Here we will
 * focus on Vector3
 *
 * A vector3 is similar to a python tuple that contain exactly 3 snek objects
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declare our snek_object_t so we can have circular refs in the other
// structures
// NOTE SO I JUST LEARNED THAT IN ORDER FOR FORWARD DECLARATIONS TO WORK MY
// STRUCTS AND SUCH NEED ACTUAL NAMES
typedef struct SnekObject snek_object_t;
typedef struct SnekVector3 snek_vector_t;

// an enum with a single value INTEGER
// Add the new enum value for floats
// Add the new enum for string
// Add a new enum value for vector3
typedef enum
{
    INTEGER = 1,
    FLOAT,
    STRING,
    VECTOR3,
} snek_object_kind_t;

// create a new struct called snek_vector_t with 3 fields
typedef struct SnekVector3
{
    snek_object_t *x;
    snek_object_t *y;
    snek_object_t *z;
} snek_vector_t;

// a union called snek_object_data_t with a single member, an integer named
// v_int
// Add a new float field as v_float
// Add a new string field as v_string
// Add a new vector3 field as v_vector3
typedef union
{
    int v_int;
    float v_float;
    char *v_string;
    snek_vector_t v_vector3;
} snek_object_data_t;

// a struct declaration called snek_object_t with 2 members
//      ▫️ a member of type snek_object_kind_t named kind
//      ▫️ a member of type snek_object_data_t named data
typedef struct SnekObject
{
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;


// function declarations:
snek_object_t *new_snek_integer(int);
snek_object_t *new_snek_float(float);
snek_object_t *new_snek_string(char *);
snek_object_t *new_snek_vector3(snek_object_t *, snek_object_t *, snek_object_t *);

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
    free(int_object3);

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
    free(float_object3);

    // quick example of how a string is just an array of chars
    char *my_string = "hello world";
    for (char *i = my_string; *i != 0; i++)
    {
        printf("%c ", *i);
    }
    printf("\n\n");

    printf("\nTest 'test_str_copied':\n");
    char *input = "Hello, World!";
    snek_object_t *obj = new_snek_string(input);
    printf("Pointers should not be equal -- Input: %p vs Object: %p\n", obj->data.v_string, input);
    printf("obj->kind should be 3 for STRING and it is %d\n", obj->kind);
    printf("The strings themselves should be equal -- \n"
           "\tObject: %s\n"
           "\tInput: %s\n",
           obj->data.v_string, input);
    free(obj->data.v_string);
    free(obj);

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

snek_object_t *new_snek_string(char *value)
{
    // allocate the memory and confirm the allocation
    snek_object_t *ptr = malloc(sizeof(snek_object_t));
    if (ptr == NULL)
    {
        return NULL;
    }
    // calculate the length of the string passed in and allocate memory
    // and confirm the allocation
    size_t len = strlen(value) + 1;
    char *string = malloc(sizeof(char) * len);
    if (string == NULL)
    {
        free(ptr);
        return NULL;
    }
    // copy the data from input value to new string field with strcpy
    strcpy(string, value);
    // set kind field to appropriate enum and store the new sting in the obj
    ptr->kind = STRING;
    ptr->data.v_string = string;
    // return my new ptr
    return ptr;
}

snek_object_t *new_snek_vector3(
    snek_object_t *x,
    snek_object_t *y,
    snek_object_t *z)
{
    // if any of the imputs are null return null
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }
    // allocate and confirm memory for new snek_object_t pointer
    snek_object_t *ptr = malloc(sizeof(snek_object_t));
    if (ptr == NULL)
    {
        return NULL;
    }
    // set the kind field to the appropriate enum
    ptr->kind = VECTOR3;
    // create a new snek_vector_t struct and set the fields with inputs
    snek_vector_t vec = {.x=x,.y=y,.z=z};
    // set the v_vector3 field of the new ptr to our new snek_vector_t
    ptr->data.v_vector3.x = x;
    ptr->data.v_vector3.y = y;
    ptr->data.v_vector3.z = z;
    // return our new pointer
    return ptr;
}