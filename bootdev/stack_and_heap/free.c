/**Free
 * 
 * The free function deallocates memory that was previously allocated
 * by malloc, calloc, or realloc.
 * 
 * IMPORTANT: free does not change the value stored in the memory,
 * and it doesn't even change the address stored in the pointer. 
 * Instead, it simply informs the OS that the memory can be used
 * again. This is one of the dangers of C UAF (Use After Free) bugs,
 * vulnerabilities, and in turn hacks.
 * 
 * Forgetting to Free: 
 * Forgetting to call free leads to memory leaks. This means that 
 * the allocated memory remains occupied and cannot be reused, even
 * though the program no longer needs it. Over time, if a program 
 * continues to allocate memory without freeing it, the program
 * may run out of memory and crash. 
 * 
 * Memory leaks are one of the most common bugs in C programs, and
 * they can be difficult to track down because the memory is still
 * allocated and accessible, even though it is no longer needed. 
 * 
 * Assignment: 
 *  1. Run the code in its current state. After a number of successful
 *     allocations I get a failure. The program is running out of
 *     memory due to a leak.
 * 
 *     See how it's calling the allocate_scalar_list function in a
 *     loop? Well, the lists aren't needed from loop to loop, so 
 *     they should be freed at the end of each iteration. If we do
 *     that, we should be able to allocate as many lists as we want
 *     (because we return the memory in between iterations) 
 * 
 *  2. Fix the code by freeing the allocated list at the end of 
 *     each loop.
 */

#include <stdio.h>
#include <stdlib.h>

int *allocate_scalar_list(int,int);

int main(int argc, char const *argv[])
{
    const int num_lists = 500;
    for (int i = 0; i < num_lists; i++) {
        int *lst = allocate_scalar_list(50000, 2);
        if (lst == NULL) {
            printf("Failed to allocate list\n");
            return 1;
        } else {
            printf("Allocated list %d\n", i);
        }
        free(lst);
    }
    return 0;
}

int *allocate_scalar_list(int size, int mult) {
    int *lst = (int *)malloc(size * sizeof(int));
    if (lst == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        lst[i] = i * mult;
    }
    return lst;
}
