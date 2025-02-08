/** Multiple Types
 * 
 * So I know see that I can push both int and int* types into my stack
 * (again, horrible idea). 
 * 
 * In this example, I'll see that not only can I push values and pointers
 * onto the same stack, but I can also push different types of values into
 * the same stack. 
 * 
 * This is once again a terrible idea, but the thrust of what I'm getting at
 * here is: 
 *      ▫️ C DOESN'T CARE WHAT I PUT IN MEMORY, IT'S BYTES ALL THE WAY DOWN
 * 
 * Fortunately, C doesn't let me do these types of conversions automatically,
 * which means I have to be doing this deliberately and explicitly, so one 
 * would think I know what I'm doing by going this route ... 
 * 
 * But C will still let me do it. When I'm working with void*, I'm working
 * with raw memory addresses, and I can cast them to anything I want. 
 */

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
void scary_double_push(stack_t *);
void stack_push_multiple_types(stack_t*);

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

    printf("\nTest #5 (heterogenous_stack)\n");
    scary_double_push(s2);
    printf("Count should now be 4 and it is %zu\n", s2->count);
    // Not sure what's happening here and why I can't get this to come out correctly
    // I get it now, the warning I'm getting is expected. Cuz I told the compiler this
    // was a void pointer when it was actually just a plan int. So when I cast it 
    // back to a plain int the compiler is questioning what I'm doing. makes sense.
    printf("The third item ([2]) should be 1337 and it is %d\n", (int)s2->data[2]);
    printf("The top item (4th [3]) should be 1024 and it is %d\n", *(int *)(s2->data[s->count - 1]));

    printf("\nTest #6 (multiple_types_stack)\n");
    stack_push_multiple_types(s2);
    printf("Count should now be 6 and it is %zu\n", s2->count);
    printf("The fifth item ([4]) should be 3.14 and it is %f\n",*(float*)s2->data[4]);
    printf("The top item (6th [5]) should be the string 'Sneklang is blazingly slow!' and it is %s\n",(char*)s2->data[5]);

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

void stack_free(stack_t *stack)
{
    // If the stack is NULL return immediately
    if (stack == NULL)
        return;
    // If the stack data is not null, free the stack data.
    // Easy to forget this step
    if (stack->data)
        free(stack->data);
    // free the stack it self
    free(stack);
}

void scary_double_push(stack_t *s)
{
    // push the value 1337 directly onto the stack, don't
    // forget to cast it to void*
    stack_push(s, (void *)1337);
    // allocate memory for a new int on the heap
    int *i = malloc(sizeof(int));
    *i = 1024;
    stack_push(s, i);
}

void stack_push_multiple_types(stack_t *s) {
    // allocate a float* on the heap and set the value to 3.14
    float *f = malloc(sizeof(float));
    *f = 3.14;
    // push the new float* onto the stack, i forgot to cast 🤦🏽‍♂️
    stack_push(s,(void*)f);
    // allocate a char* on the heap and set the value to 
    // "Sneklang is blazingly slow!" (need to allocate 50 so it fits)
    // this didn't pass so adding two steps to get an actual len
    char *str = "Sneklang is blazingly slow!";
    size_t len = strlen(str) + 1;
    // now I can use the above to allocate the exact memory needed.
    char *string = malloc(sizeof(char) * len);
    // This got me again. Working with strings in C is tricky. Every where else
    // I set *var = scalar_value
    // But with strings I don't dereference since the value isn't scalar, its
    // a pointer itself. so instead of what I had *str = ...; its str = ...;
    strcpy(string,str);
    stack_push(s,(void*)string);
}

// So my way worked but I guess the guessed amount malloc'd for bootdev isn't
// enough to pass. So I need to get an actual length which means creating the 
// string or array first and getting its len for the malloc step.