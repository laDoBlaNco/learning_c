/** The Heap
 * 
 * Heap memory as opposed to stack, a a pool of long-lived memory
 * shared across the entire program. Stack memory is automatically
 * allocated and deallocated as functions are called and return, but
 * heap memory is allocated and deallocated as needed, and in C by
 * me explicitly, independent of the burdensome  shackles of function
 * calls
 * 
 * When I need to store data that outlive the function that created 
 * it, I'll send it to the heap. In Go this is the reason for the 
 * escape analysis to determine if stack or heap memory should be 
 * used. The heap is called 'dynamic memory' because it's allocated
 * and deallocated as needed. Take a log at the example below
 * 'new_int_array'
 * 
 * Since the size of my array isn't known at compile time, I can't 
 * put it on the stack. Instead I allocate memory on the heap using
 * <stdlib>'s 'malloc' function. It takes a number of bytes to allocate
 * as an argument (size * sizeof(int)) and returns a pointer to the
 * allocated memory (a void * that we cast to an int *)
 * 
 * Here is a diagram of what happened in memory: 
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/Zs3j5Gx.png
 * 
 * The new_int_array function's size argument is just an integer
 * it's pushed onto the stack. Assuming size is 6, when malloc
 * is called I'm given enough memory to store 6 integers on the 
 * heap, and I'm given  the address of the start of that newly
 * allocated memory. I then store it in a new local variable called
 * new_arr. The address is stored on the stack, but the data it points
 * to is in the heap. 
 * 
 * Let's look at some code that uses new_int_array now: 
 * 
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/GSgP7bn.png
 * 
 * The free function from <stdlib.h> returns (deallocates) that memory
 * for use elsewhere. It's important to note that THE POINTER STILL 
 * EXISTS, BUT SHOULDN'T BE USED ANYMORE. This is another way that a
 * DANGLING POINTER can be created, pointing to deallocated memory
 * 
 * Assignment: 
 *  1. Run the get_full_greeting function in its current state. If
 *     I look at the code below, I'll notice that its testing to
 *     ensure that a pointer to stack memory isn't returned (which
 *     I should never do, because it's undefined behavior). I get
 *     a warning that I'm returning the address of a local variable
 *     and when I try to print the result its null. Null pointer or
 *     dangling pointer major dicho
 *  2. Fix the get_full_greeting function so that it allocates
 *     memory on the heap and returns a pointer to that memory. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

int *new_int_array(int);

// assignment
char *get_full_greeting(char *greeting, char *name, int size);

int main(int argc, char const *argv[]) {
    
    int *arr_of_6 = new_int_array(6);
    arr_of_6[0] = 69;
    arr_of_6[1] = 42;
    arr_of_6[2] = 420;
    arr_of_6[3] = 1337;
    arr_of_6[4] = 7;
    arr_of_6[5] = 0;
    // This data is stored in the heap and when we are done
    // with it we need to MANUALLY deallocate it using <stdlib.h>
    // 'free' function.
    free(arr_of_6);

    // assignment: 
    char *result = get_full_greeting("Hello", "Alice", 5);
    printf("The result is %s\n",result);
    free(result);
    result = NULL;

    return 0;
}

int *new_int_array(int size) {
    int *new_arr = (int*)malloc(size * sizeof(int)); // allocate memory in heap
    // then check result of allocation, Go gets that style from C
    if (new_arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // exit if allocation fails
    }
    return new_arr; // return the pointer, malloc'd. Recall that 
    // in the previous lesson when our function died it left us
    // a dangling pointer because that was created in a stackframe
    // but when using malloc, our data has escaped the scope of our
    // function and can live on after the function dies.
}

char *get_full_greeting(char *greeting, char *name, int size) {
    // char full_greeting[100]; // first our allocation happens in the
    char *full_greeting = (char *)malloc(size * sizeof(char));
    // function on the stack
    snprintf(full_greeting, size, "%s %s",greeting,name);
    return full_greeting; // if I return an array I'm really returning
    // a pointer (arrays decay to simple pointers)
}

// helper function to check if a pointer is on the stack
bool is_on_stack(void *ptr) {
    void *stack_top = __builtin_frame_address(0);
    uintptr_t stack_top_addr = (uintptr_t)stack_top;
    uintptr_t ptr_addr = (uintptr_t)ptr;

    // check within a threshold in both directions (e.g., 1MB)
    uintptr_t threshold = 1024;

    return ptr_addr >= (stack_top_addr - threshold) && ptr_addr <= (stack_top_addr + threshold);
}



