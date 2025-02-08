/**String: 
 * 
 * Now, here with string it gets interesting. I'm going to do something additional
 * in regards to the allocation. When I allocate memory for a snek object, that
 * reserves memory for the object itself. Small data types like integers and 
 * floats are stored direclty in the object, so there's no need for additional
 * memory allocation
 * 
 * strings however a different story. Strings in C are just arrays of chars, remember
 * and because they can be of any length, I need to dynamically allocate memory
 * for the string data separately from the object itself
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// an enum with a single value INTEGER
// Add the new enum value for floats
// Add the new enum for string
typedef enum
{
    INTEGER = 1,
    FLOAT,
    STRING,
} snek_object_kind_t;

// a union called snek_object_data_t with a single member, an integer named
// v_int
// Add a new float field as v_float
// Add a new string field as v_string
typedef union
{
    int v_int;
    float v_float;
    char *v_string;
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
snek_object_t *new_snek_string(char*);

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
    for (char *i = my_string;*i!=0;i++) {
        printf("%c ",*i);
    }
    printf("\n\n");

    printf("\nTest 'test_str_copied':\n");
    char *input = "Hello, World!";
    snek_object_t *obj = new_snek_string(input);
    printf("Pointers should not be equal -- Input: %p vs Object: %p\n",obj->data.v_string,input);
    printf("obj->kind should be 3 for STRING and it is %d\n",obj->kind);
    printf("The strings themselves should be equal -- \n"
           "\tObject: %s\n"
           "\tInput: %s\n",
           obj->data.v_string,input  
    );
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

snek_object_t *new_snek_string(char* value)
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
    strcpy(string,value);
    // set kind field to appropriate enum and store the new sting in the obj
    ptr->kind = STRING;
    ptr->data.v_string = string;
    // return my new ptr
    return ptr;
}