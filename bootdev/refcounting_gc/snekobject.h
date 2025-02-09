/**Sneklang Object Header
 *
 * Trying to get used to the process of programming in C, so I'll 
 * create and used an actual header file in this chapter, rather than
 * just copying the same stuff over and over
 *
 */
#include <stdbool.h>
#include <stddef.h>

// Type Declarations
typedef struct SnekObject snek_object_t;

// Type Definitions
typedef struct
{
    size_t size;
    snek_object_t **elements;
} snek_array_t;

typedef struct
{
    snek_object_t *x;
    snek_object_t *y;
    snek_object_t *z;
} snek_vector_t;

typedef enum SnekObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY,
} snek_object_kind_t;

typedef union SnekObjectData
{
    int v_int;
    float v_float;
    char *v_string;
    snek_vector_t v_vector3;
    snek_array_t v_array;
} snek_object_data_t;

typedef struct SnekObject
{
    snek_object_kind_t kind;
    snek_object_data_t data;
    // adding a refcount field
    int refcount;
} snek_object_t;

// Function Declarations
snek_object_t *new_snek_integer(int);
snek_object_t *new_snek_float(float);
snek_object_t *new_snek_string(char *);
snek_object_t *new_snek_vector3(
    snek_object_t *x,
    snek_object_t *y,
    snek_object_t *z);
snek_object_t *new_snek_array(size_t);
void refcount_inc(snek_object_t*);
void refcount_dec(snek_object_t*);
void refcount_free(snek_object_t*);
