/**Pros and Cons
 * 
 * To solve the cyclic reference issue (and to force myself to 
 * implement another GC algorithm 🤔) I'm going to implement a 
 * Mark and Sweep GC
 * 
 * Pros of Mark and Sweep: 
 *      ▫️ Can detect cycles, and thus prevent memory leaks in certain
 *        cases
 *      ▫️ Less on-demand book keeping (Remember all work done by GC is
 *        'wasted' - it doesn't make our custom AI product any faster)
 *      ▫️ Reduces potential performance degradation in highly multi-
 *        threaded programs (refcounting requires atomic updates for
 *        thread safety)
 * 
 * Cons of Mark and Sweep: 
 *      ▫️ More complex to implement (here we go)
 *      ▫️ Can cause 'stop-the-world' pauses when lots of objects exist
 *        and must be freed (resulting in poor performance) This happens
 *        with Go
 *      ▫️ Higher memory overhead
 *      ▫️ Less predictable performance
 * 
 * So after including all the boiler plate below I have vm_t which is
 * a kinda virtual machine that will simulate what would normally 
 * be happening if sneklang were a real thing. Its a simplified 
 * version since I'm only concerned with the gc aspects. 
 * 
 * If I look at the vm header stuff below I see that vm_t has a field
 * *frames which holds a stack of frames, which are pushed and popped
 * as I enter and exit new scopes. At each scope entrance ( in this case
 * function calls) a new stack frame is pushed onto the frames stack.
 * When we exit a scope (function return), I pop the stack frame off
 * the frames stack. Since we are using void* to work with generics
 * in C, I can't actually tell what the data type held by the stack_t
 * is for each field. I'll have to write some wrapper functions later
 * to help me make sure that I don't accidentally push the wrong 
 * kinds of data into the stack (yay C!). Haters!
 * 
 * The objects field is also a stack, but it holds snek_object_t pointers
 * 
 * in VM STUFF below I need to complete the vm_new function and the
 * vm_free functions.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


// SNEKOBJECT HEADER STUFF
typedef struct SnekObject snek_object_t;

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
} snek_object_t;

// stack header stuff
typedef struct Stack
{
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

stack_t *stack_new(size_t capacity);
void stack_push(stack_t *stack, void *obj);
void *stack_pop(stack_t *stack);
void stack_free(stack_t *stack);
void stack_remove_nulls(stack_t *stack);

// VM HEADER STUFF
typedef struct VirtualMachine
{
    stack_t *frames;
    stack_t *objects;
} vm_t;

vm_t *vm_new();
void vm_free(vm_t *vm);

// my main block            
int main(int argc, char const *argv[])
{
    printf("\nCOMPILED SUCCESSFULLY\n\n");

    return 0;
}

// STACK STUFF
void stack_push(stack_t *stack, void *obj)
{
    if (stack->count == stack->capacity)
    {
        // double stack capacity to avoid reallocation
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
        if (stack->data == NULL)
        {
            // unable to realloc, just exit 🫠 get gud
            exit(1);
        }
    }
    stack->data[stack->count] = obj;
    stack->count++;
    return;
}

void *stack_pop(stack_t *stack)
{
    if (stack->count == 0)
    {
        return NULL;
    }
    stack->count--;
    return stack->data[stack->count];
}

void stack_free(stack_t *stack)
{
    if (stack == NULL)
    {
        return;
    }
    if (stack->data != NULL)
    {
        free(stack->data);
    }
    free(stack);
}

void stack_remove_nulls(stack_t *stack)
{
    size_t new_count = 0;

    // iterate through the stack and compact non-NULL pointers
    for (size_t i = 0; i < stack->count; ++i)
    {
        if (stack->data[i] != NULL)
        {
            // this one is tricky cuz I'm using the new_count and then
            // incrementing it right after using it. 
            stack->data[new_count++] = stack->data[i];
        }
    }
    // update the count to reflect the new number of elements
    stack->count = new_count;

    // optionally I might want to zero out the remaining slots
    for (size_t i = new_count; i < stack->capacity; ++i) // why the hell am I using a prefix here
    {
        stack->data[i] = NULL;
    }
}

stack_t *stack_new(size_t capacity)
{
    stack_t *stack = malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        return NULL;
    }
    stack->count = 0;
    stack->capacity = capacity;
    stack->data = malloc(stack->capacity * sizeof(void*));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

// VM STUFF
vm_t *vm_new()
{
    vm_t *vm = malloc(sizeof(vm_t));
    if (vm == NULL)
    {
        return NULL;
    }
    // this almost got me and its the first time I'm chaining ptrs
    // like this. last time I saw this syntax was with PHP clases 😅
    // but since vm is a pointer to frames which is also a pointer to
    // capacity. They seem to be like arrays of pointers. But rather 
    // **capacity, since they are connecting from different structs
    // its vm->frames->capacity. But I need to use the stack_new 
    // function, so chaning the below: 
    // vm->frames->capacity = 8;
    // vm->objects->capacity = 8;
    vm->frames = stack_new(8);
    // this seems like double-dipping as we are already confirming
    // allocation in the stack_new function
    if (vm->frames == NULL)
    {
        free(vm);
        return NULL;
    }
    vm->objects = stack_new(8);
    if(vm->objects == NULL)
    {
        free(vm);
        return NULL;
    }
    return vm;
}

void vm_free(vm_t *vm)
{
    if(vm == NULL)
    {
        return;
    }
    stack_free(vm->frames);
    stack_free(vm->objects);
    free(vm);
}

