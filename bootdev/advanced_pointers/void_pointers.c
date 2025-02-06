/**Void Pointers
 * 
 * So I've already learned about 'void' with regards to functions,
 * it literally means 'nothing' in C. Its used in a few different
 * contexts: 
 *      ▫️ void update_soldier(soldier_t *s); means the function 
 *        returns nothing
 *      ▫️ soldier_t new_soldier(void); means the function takes no
 *        arguments
 * 
 * And, because C likes re-using ideas but with slightly different
 * meanings (the genius of the design can't be understood by us mere
 * mortals) void also has another use!
 * 
 * A void* 'void pointer' tells the compiler that this pointer could
 * point to ANYTHING This is why void pointers are also known as a
 * GENERIC POINTER. Since void pointers do not have a specific data
 * type, they can't be directly dereferenced or used in pointer 
 * arithmetic without casting them to another pointer type first. 
 * 
 * Casting to Void Pointers
 * Casting to and from void pointers in C is unique because void 
 * pointers are type-agnostic. When casting a specific type pointer
 * to a void pointer, no type information is retained, allowing the
 * void pointer to point to any data type. Howerver I MUST cast a
 * void pointer back ot its original type before dereferencing it,
 * as direct dereferencing is not possible. 
 * 
 * A common pattern is to store generic data in one variable, and 
 * the type of that data in another variable. This is useful when
 * I need to pass data around without knowing its type  at compile
 * time. Which is kinda what malloc is doing for example. 
 * 
 * Assignment: 
 * Complete the snek_zero_out function. It accepts a generic pinter
 * one of: 
 *      ▫️ snek_int_t
 *      ▫️ snek_float_t
 *      ▫️ snek_bool_t
 */

#include <stdio.h>


typedef enum DATA_TYPE{
    INT,
    FLT,
} data_type_t;

void print_value(void *,data_type_t);

// Assignment Types: 
typedef enum {
    INTEGER,
    FLOAT,
    BOOL,
} snek_object_kind_t;

typedef struct {
    char *name;
    int value;
} snek_int_t;

typedef struct {
    char *name;
    float value;
} snek_float_t;

typedef struct {
    char *name;
    unsigned int value;
} snek_bool_t;

void snek_zero_out(void*,snek_object_kind_t);

int main(int argc, char const *argv[])
{
    int number = 42;
    void *generic_ptr = &number;  // not sure why I would ever do
    // this. Since I know the type of number then this would be a form of
    // casting TO a void ptr I know I get a void pointer from malloc, but why would
    // I deliberarely set a void pointer to a value with a known
    // type??? 🤔 So I guess since this is a form of casting, its really
    // the same as whats happening with malloc. malloc is what 'casts'
    // the value I ask for to a void pointer. So that's why I need to 
    // cast what I receive from malloc to a specified type or BACK to the
    // the type that I know it has or will have. 

    // This won't work since no type information is retained
    // printf("Value of number: %d\n",*generic_ptr);

    // this works: Casting to appropriate type before dereferencing.
    printf("Value of number: %d\n",*(int*)generic_ptr);


    int num = 42;
    print_value(&num,INT);

    float dec = 3.14;
    print_value(&dec, FLT);


    // ASSIGNMENT: 
    snek_int_t integer;
    integer.value = 42;
    snek_zero_out(&integer,INTEGER);
    printf("\n\nTest #1\n");
    printf("Integer should be zeroed out and it is: %d\n",integer.value);

    snek_float_t float_num;
    float_num.value = 3.14;
    snek_zero_out(&float_num,FLOAT);
    printf("\nTest #2\n");
    printf("Float should be zeroed out and it is: %f\n",float_num.value);

    snek_bool_t boolean;
    boolean.value = 1;
    snek_zero_out(&boolean,BOOL);
    printf("\nTest #3\n");
    printf("Boolean should be zeroed out and it is: %d\n",boolean.value);

    integer.value = -100;
    float_num.value = -99.99;
    boolean.value = 255;
    snek_zero_out(&integer,INTEGER);
    snek_zero_out(&float_num,FLOAT);
    snek_zero_out(&boolean,BOOL);
    printf("\nTest #4\n");
    printf("Negative integer should be zeroed out and it is: %d\n",integer.value);
    printf("Negative float_num should be zeroed out and it is: %f\n",float_num.value);
    printf("Negative boolean should be zeroed out and it is: %d\n",boolean.value);


    return 0;
}

// this would work with accepting a ptr directly from malloc
// and using the function to cast it before using it. 
void print_value(void *ptr,data_type_t type)
{
    switch(type) {
        case INT: printf("Value: %d\n", *(int*)ptr);break;
        case FLT: printf("Value: %f\n",*(float*)ptr);
        default: printf("Uknown type");
    }
}

void snek_zero_out(void* ptr,snek_object_kind_t kind) {
    switch(kind) {
        case INTEGER: ((snek_int_t *)ptr)->value = 0; break;
        case FLOAT: ((snek_float_t*)ptr)->value = 0.0; break;
        case BOOL: ((snek_bool_t*)ptr)->value = 0; break;
        default: printf("Unknown kind of type encountered!\n");
    }
}