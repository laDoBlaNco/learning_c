/**Sweep:
 *
 * I'm finally here at the end. Sweep is the easy part. Trace was
 * probably the hardest part of the GC.
 *
 * Every object now has an 'is_marked' field that we can use to
 * determine if an object is reachable or not. All we need to do is
 * iterate over all the objects in the VM and free any object that is
 * not marked. Once its freed, we can also remove it from our VM
 *
 * One other thing that isn't obvious about sweep(): Any object that
 * is marked (we don't want to free it right now) needs to be reset
 * to 'is_marked = false'. That way the next time the mark phase
 * runs, if its not marked again itll be freed in the next cycle.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
    bool is_marked;
} snek_object_t;

void snek_object_free(snek_object_t *obj);

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

// a simple struct that holds a stack_t of snek_object_t* that represents
// the object reference in a frame
typedef struct StackFrame
{
    stack_t *references;
} frame_t;

// the main functiosn for garbage collection
void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);

// Helper functions for 'trace'
void trace_blacken_object(stack_t *gray_objects, snek_object_t *obj);
void trace_mark_object(stack_t *gray_objects, snek_object_t *obj);

// This is the function that gets called to actually do the garbage
// collection, but is just composed of the functions above 'mark', 'trace',
// and 'sweep'.
// Don't worry, it's not going to delete my code, I hope! 🤔🤓
void vm_collect_garbage(vm_t *vm);

// the others
vm_t *vm_new();
void vm_free(vm_t *vm);
void vm_track_object(vm_t *vm, snek_object_t *obj);
void vm_frame_push(vm_t *vm, frame_t *frame);
frame_t *vm_new_frame(vm_t *vm);
void frame_free(frame_t *frame);
void frame_reference_object(frame_t *frame, snek_object_t *obj);

// SNEKNEW HEADER STUFF
snek_object_t *new_snek_integer(vm_t *vm, int value);
snek_object_t *new_snek_float(vm_t *vm, float value);
snek_object_t *new_snek_string(vm_t *vm, char *value);
snek_object_t *new_snek_vector3(vm_t *vm,
                                snek_object_t *x,
                                snek_object_t *y,
                                snek_object_t *z);
snek_object_t *new_snek_array(vm_t *vm, size_t size);

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
    stack->data = malloc(stack->capacity * sizeof(void *));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

// VM STUFF

void vm_collect_garbage(vm_t *vm)
{
    mark(vm);
    trace(vm);
    sweep(vm);
}

void sweep(vm_t *vm)
{
    if (vm == NULL)
    {
        return;
    }

    // iterate over all the VMs objects
    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_t *obj = vm->objects->data[i];
        // if object is marked, reset is_marked to false and continue
        if (obj->is_marked)
        {
            obj->is_marked = false;
            continue;
        }
        free(obj);
        vm->objects->data[i] = NULL;
    }

    stack_remove_nulls(vm->objects);
}

void trace(vm_t *vm)
{
    // create a new stack (stack_new) with a capacity of 8 called
    // gray_objects. Confirm the allocation.
    stack_t *gray_objects = stack_new(8);
    if (gray_objects == NULL)
    {
        return;
    }
    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_t *obj = vm->objects->data[i];
        if (obj->is_marked)
        {
            stack_push(gray_objects, obj);
        }
    }

    while (gray_objects->count > 0)
    {
        trace_blacken_object(gray_objects, stack_pop(gray_objects));
    }

    stack_free(gray_objects);
}

void trace_blacken_object(stack_t *gray_objects, snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }
    // if obj is int, float, or string, don't do anything.
    // If its a vector3 call trace_mark_object on each (x,y,z)
    // if its an array call trace-mark_object on all elements
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
    case STRING:
        return;
    case VECTOR3:
        trace_mark_object(gray_objects, obj->data.v_vector3.x);
        trace_mark_object(gray_objects, obj->data.v_vector3.y);
        trace_mark_object(gray_objects, obj->data.v_vector3.z);
        break;
    case ARRAY:
        for (size_t i = 0; i < obj->data.v_array.size; i++)
        {
            trace_mark_object(gray_objects, obj->data.v_array.elements[i]);
        }
    }
}

void trace_mark_object(stack_t *gray_objects, snek_object_t *obj)
{
    // if object is null or already marked, return immediately
    if (obj == NULL || obj->is_marked == true)
    {
        return;
    }
    // otherwise mark the object and push it onto the stack
    obj->is_marked = true;
    stack_push(gray_objects, obj);
}

void mark(vm_t *vm)
{
    if (vm == NULL)
    {
        return;
    }
    for (int i = 0; i < vm->frames->count; i++)
    {
        // we have to do this since we are using void* we need to tell
        // C what we are working with so it can following along
        // I'm telling C that I'm dealing with individual frames here
        frame_t *frame = vm->frames->data[i];
        for (int j = 0; j < frame->references->count; j++)
        {
            // here is the same, first deal with the void* cast
            // and I'm that i'm dealing with individual snek_objects

            snek_object_t *obj = frame->references->data[j];
            obj->is_marked = true;
            // So key thing to note here. VS Code and C can't follow my
            // pointer references unless it knows what types I'm working
            // with. As soon as I added in frame_t and snek_object_t
            // above, I could use -> freely and track down my objects. 🤓
            // C compiler only knows its a void *, but not how to trace
            // it back to anything.
        }
    }
}

void frame_reference_object(frame_t *frame, snek_object_t *obj)
{
    if (frame == NULL || obj == NULL)
    {
        return;
    }

    stack_push(frame->references, (void *)obj);
}

void vm_free(vm_t *vm)
{
    if (vm == NULL)
    {
        return;
    }

    for (size_t i = 0; i < vm->frames->count; i++)
    {
        frame_free(vm->frames->data[i]);
    }
    stack_free(vm->frames);

    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_free(vm->objects->data[i]);
    }
    stack_free(vm->objects);

    free(vm);
}

void vm_track_object(vm_t *vm, snek_object_t *obj)
{
    if (vm == NULL || obj == NULL)
    {
        return;
    }
    stack_push(vm->objects, (void *)obj);
}

// Complete vm_frame_push which will take a vm and a frame and
// stack_push it onto vm->frames stack
void vm_frame_push(vm_t *vm, frame_t *frame)
{
    if (vm == NULL || frame == NULL)
    {
        // don't return NULL since this function is void return
        return;
    }
    // the (void*) cast is just for clarity
    stack_push(vm->frames, (void *)frame);
}

// complete  the vm_new_frame function:
frame_t *vm_new_frame(vm_t *vm)
{
    if (vm == NULL)
    {
        return NULL;
    }
    // allocate a new frame_t on the heap
    frame_t *frame = malloc(sizeof(frame_t));
    if (frame == NULL)
    {
        return NULL;
    }
    // initialize frame references with a stack_new(8)
    frame->references = stack_new(8);
    if (frame->references == NULL)
    {
        free(frame);
        return NULL;
    }
    // push new frame onto the vm->frames stack
    vm_frame_push(vm, frame);
    // return the new frame
    return frame;
}

// complete the frame_free function
void frame_free(frame_t *frame)
{
    if (frame == NULL)
    {
        return;
    }
    stack_free(frame->references);
    free(frame);
}

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
    if (vm->objects == NULL)
    {
        free(vm);
        return NULL;
    }
    return vm;
}

// SNEKNEW STUFF

snek_object_t *_new_snek_object(vm_t *vm)
{
    snek_object_t *obj = calloc(1, sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->is_marked = false;
    vm_track_object(vm, obj);
    return obj;
}

snek_object_t *new_snek_array(vm_t *vm, size_t size)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
    if (elements == NULL)
    {
        free(obj);
        return NULL;
    }
    obj->kind = ARRAY;
    obj->data.v_array = (snek_array_t){.size = size, .elements = elements};
    return obj;
}

snek_object_t *new_snek_vector3(
    vm_t *vm,
    snek_object_t *x,
    snek_object_t *y,
    snek_object_t *z)
{
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};
    return obj;
}

snek_object_t *new_snek_integer(vm_t *vm, int value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = INTEGER;
    obj->data.v_int = value;

    return obj;
}

snek_object_t *new_snek_float(vm_t *vm, float value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_string(vm_t *vm, char *value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    int len = strlen(value);
    char *dst = malloc(len + 1);
    if (dst == NULL)
    {
        free(obj);
        return NULL;
    }
    strcpy(dst, value);

    obj->kind = STRING;
    obj->data.v_string = dst;
    return obj;
}

// THE SNEKOBJECT STUFF
void snek_object_free(snek_object_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
        break;
    case STRING:
        free(obj->data.v_string);
        break;
    case VECTOR3:
        break;
    case ARRAY:
        free(obj->data.v_array.elements);
        break;
    }
    free(obj);
}
