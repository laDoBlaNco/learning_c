/**Length:
 *
 * Now that I have all sorts of snek objects (integers, floats, strings, arrays
 * etc.) I need a convenient way to get the length of any snek object. In
 * Python (Sneklang's dreaded competitor) it's as easy as
 *      print(len(x))
 *
 * As a Python dev, I don't have to know the value of x ahead of time cuz
 * Python keeps track of it under_the_hood. I need to get this to do the same
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// forward declare our snek_object_t so we can have circular refs in the other
// structures
// NOTE SO I JUST LEARNED THAT IN ORDER FOR FORWARD DECLARATIONS TO WORK MY
// STRUCTS AND SUCH NEED ACTUAL NAMES
typedef struct SnekObject snek_object_t;
// typedef struct SnekVector3 snek_vector_t;

// an enum with a single value INTEGER
// Add the new enum value for floats
// Add the new enum for string
// Add a new enum value for vector3
// Add a new enum value for array
typedef enum
{
    INTEGER = 1,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY,
} snek_object_kind_t;

// create a new struct called snek_array_t with 2 fields (size, elements)
typedef struct SnekArray
{
    size_t size;
    snek_object_t **elements;
} snek_array_t;

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
    snek_array_t v_array;
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
snek_object_t *new_snek_array(size_t);
bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value);
snek_object_t *snek_array_get(snek_object_t *array, size_t index);
int snek_length(snek_object_t *);

int main(int argc, char const *argv[])
{
    printf("\nIT COMPILED AT LEAST!!!\n\n");

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
    snek_vector_t vec = {.x = x, .y = y, .z = z};
    // set the v_vector3 field of the new ptr to our new snek_vector_t
    // ptr->data.v_vector3.x = x;
    // ptr->data.v_vector3.y = y;
    // ptr->data.v_vector3.z = z;
    ptr->data.v_vector3 = vec;
    // return our new pointer
    return ptr;
}

snek_object_t *new_snek_array(size_t size)
{
    // allocate and confirm memory for new snek_object_t pointer
    snek_object_t *ptr = malloc(sizeof(snek_object_t));
    if (ptr == NULL)
    {
        return NULL;
    }
    // allocate memory for a new pointer to an array of snek objects
    // I'm not storing the actual object here just a pointer which all
    // have the same size
    snek_object_t **parr = calloc(size, sizeof(snek_object_t *));
    if (parr == NULL)
    {
        free(ptr);
        return NULL;
    }
    // set the kind field to the appropriate enum
    ptr->kind = ARRAY;
    // create a new snek_array_t struct
    snek_array_t array = {.size = size, .elements = parr};
    ptr->data.v_array = array;

    // return my pointer
    return ptr;
}

// Complete snek_array_set function
bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value)
{
    // if object or new value are null return false, or if the kind is not array
    if (array == NULL ||
        value == NULL ||
        array->kind != ARRAY ||
        index >= array->data.v_array.size)
    {
        return false;
    }
    array->data.v_array.elements[index] = value;
    return true;
}

snek_object_t *snek_array_get(snek_object_t *array, size_t index)
{
    if (array == NULL ||
        array->kind != ARRAY ||
        index >= array->data.v_array.size)
    {
        return NULL;
    }
    return array->data.v_array.elements[index];
}

int snek_length(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return -1;
    }
    switch(obj->kind)
    {
        case INTEGER: 
        case FLOAT: return 1;
        case STRING: return strlen(obj->data.v_string);
        case VECTOR3: return 3;
        case ARRAY: return obj->data.v_array.size;
        default: return -1;
    }
}
