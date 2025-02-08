/**Stack Free
 *
 * In C, I don't have a lot of abstractions, which for me is the fun of 
 * programming in C. I love to see and understand whats really happening. 
 * There are no classes, destructors, functors, monads, made-up-category-theory-
 * words, etc. 
 * 
 * I've got DATA. And I've got FUNCTIONS. Just the way God (Dennis Ritchie)
 * intended. 😆
 * 
 * So to make it easier to work with my stack, I'm going to build my own little
 * free function that will clean up all the memory that I've allocated in my
 * stack. This will help me understand what's happening under the hood on the
 * actual stack
 * 
 * 
 */

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

stack_t *stack_new(size_t);
void stack_push(stack_t *, void *);
void *stack_pop(stack_t *);
void stack_free(stack_t *);



int main(int argc, char const *argv[])
{

    stack_t *s = stack_new(10);

    printf("\nTest #1 (create_stack)\n");
    printf("Capacity should be 10 and it is %zu\n", s->capacity);
    printf("Elements should be 0 and they are %zu\n", s->count);
    printf("Data shouldn't be NULL and it is %p\n", s->data);
    free(s->data);
    free(s);

    stack_t *s2 = stack_new(2);
    printf("\nText #2 (push_stack)\n");
    printf("Capacity should be 100 and it is %zu\n", s2->capacity);
    printf("Elements should be 0 and they are %zu\n", s2->count);
    printf("Data shouldn't be NULL and it is %p\n", s2->data);
    int a = 1;
    stack_push(s2, &a);
    stack_push(s2, &a);
    printf("Capacity should still be 2 and it is %zu\n", s2->capacity);
    printf("Elements should be count of 2 and they are %zu\n", s2->count);
    printf("s2->data[0] should equal %p and it is %p\n", &a, s2->data[0]);

    printf("\nTest #3 (stack_push to double capacity)\n");
    stack_push(s2, &a);
    printf("Capacity should now be 4 and it is %zu\n", s2->capacity);
    printf("Elements should be count of 3 and they are %zu\n", s2->count);

    printf("\nTest #4 (pop_stack)\n");
    int *popped = stack_pop(s2);
    printf("Popped pointer %p of value %d is %p -- %d\n", &a, a, popped, *popped);
    printf("Stack count should now be 2 and it's %zu\n", s2->count);
    printf("Stack capacity should still be 4 and it's %zu\n", s2->capacity);

    stack_free(s2);

    return 0;
}

void stack_push(stack_t *stack, void *obj)
{
    // I remember doing this already in Go, so I kinda have an ideal
    // already of what I need to do
    if (stack->count == stack->capacity)
    {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
        if (stack->data == NULL)
        {
            free(stack->data);
            return;
        }
    }
    stack->data[stack->count] = obj;
    stack->count += 1;
}

stack_t *stack_new(size_t capacity)
{
    stack_t *stack = malloc(sizeof(stack_t));
    if (stack == NULL)
        return NULL;

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

void *stack_pop(stack_t *stack)
{
    if (stack->count == 0)
        return NULL;
    stack->count -= 1;
    return stack->data[stack->count];
}

void stack_free(stack_t *stack) {
    // If the stack is NULL return immediately
    if (stack == NULL) return;
    // If the stack data is not null, free the stack data.
    // Easy to forget this step
    if (stack->data) free(stack->data);
    // free the stack it self
    free(stack);
}