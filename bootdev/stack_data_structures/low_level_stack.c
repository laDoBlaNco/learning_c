/**Low Level Stack
 * 
 * I've already taken courses on data structures so I know what
 * a stack basically is and how to implement one. Here I'm going to
 * implement a stack again, but this time I'm going to do it while
 * manually managing the memory of GENERIC POINTERS!
 * 
 * Here i'll get to have a deeper exploration of generics in C
 * (remember this just means 'void*) as well as creating a data
 * structure i'll later use in the mark-and-sweep gc. 
 * 
 * Assignment
 *  1. Create the Stack struct with
 *      ▫️ count is the number of elements in the stack
 *      ▫️ capacity is the number of elements the stack can hold before it needs
 *        to be resized in memory
 *      ▫️ data is a pointer to all the generic data
 * 
 *  2. Implement the stack_new function:asm
 *      ▫️ Allocate memory for a new Stack struct on the heap (stack frame)??
 *      ▫️ if allocation fails, return NULL
 *      ▫️ Initialize the count to 0
 *      ▫️ Initialize the capacity to the given value
 *      ▫️ Initialize the data by allocating enough memory for capacity number of
 *        of void*s
 *      ▫️ Return the new Stack struct
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Stack {
    size_t count;
    size_t capacity;
    // since we can't have data of different sizes we do this generically with
    // an array of void pointers. that's why its void **data;
    void **data;
} stack_t;

stack_t *stack_new(size_t);

int main(int argc, char const *argv[])
{
    stack_t *s = stack_new(3);

    printf("\nTest #1 (create_stack_small)\n");
    printf("Capacity should be 3 and it is %zu\n",s->capacity);
    printf("Elements should be 0 and they are %zu\n",s->count);
    printf("Data shouldn't be NULL and it is %p\n",s->data);

    stack_t *s2 = stack_new(100);
    printf("\nText #2 (create_stack_large)\n");
    printf("Capacity should be 100 and it is %zu\n",s2->capacity);
    printf("Elements should be 0 and they are %zu\n",s2->count);
    printf("Data shouldn't be NULL and it is %p\n",s2->data);


    free(s->data);
    free(s);

    return 0;
}

stack_t *stack_new(size_t capacity) {
    stack_t *ptr = malloc(sizeof(stack_t));
    if (ptr == NULL ) return NULL;

    ptr->count = 0;
    ptr->capacity = capacity;
    // data is a pointer to all generic data  which is allocated for capacity
    // number of void*. since malloc returns void* it'll just be malloc(capacity)??
    // NOPE, I needed to use sizeof on the void*. Remember that I'm trying to store
    // an array of pointers. Even though its void and I don't know yet what it'll
    // hold, all pointers are the same size, so I can indeed use sizeof(void*)
    ptr->data = malloc(sizeof(void *) * capacity);
    if (ptr->data == NULL) {
        free(ptr);
        return NULL;
    }
    return ptr;
}


