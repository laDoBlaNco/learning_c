/**Dynamic Memory Allocation
 * 
 * In a previouis example I saw how to allocate memory via an
 * array or create memory space suing structures. The problem with both
 * of these solutions to allocating memory is that their sizes are static
 * and have to be known at compile time. Because of this, we end up 
 * allocating too much space and not being able to allocate any more if our 
 * program grows. 
 * 
 * THE HEAP
 * The heap is a data region in ELF (linux) memory that is managed by a 
 * memory allocator. Instead of using statically defined arrays or 
 * structures, we can ask the memory allocator via a funtion called 
 * malloc to get us a certain amount of memory. For example this code
 * allocates 64 bytes of memory
 *      malloc(64);
 * 
 * ALLOCATING MEMORY
 * To use this memory I need to assign it to a variable for use later.
 * Also its important that we check the return value from malloc to make
 * sure that I get a value from the allocator telling me is succeeded, 
 * since sometimes allocators fail.
 * 
 *      employee_t *my_employee = malloc(sizeof(struct employee_t))
 *      if (my_employee == NULL) {
 *          printf("Something went wrong\n");
 *      }
 *      return -1;
 * If the var is still empty after the memory allocation, return -1
 * for failure.
 * 
 * A major part of memory management is freeing the memory when we 
 * are done with it, otherwise this is called a MEMORY LEAK and
 * could possibly us up all the system memory and eventually have our 
 * process be killed by the OS kernel. To avoid this, free the memory
 *      free(my_employee);
 *      my_employee = NULL;
 * 
 * Its not required but a good idea to set used pointers to NULL, This
 * way we avoid what's call dangling pointers or a pointer that
 * points to memory that is no longer valid or freed. 
 * 
 * 
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

typedef struct employee_t {
    int id;
    int income;
    bool staff;
}employee_t;

void initialize_employee(employee_t *e) {
    e->id = 0;
    e->income = 0;
    e->staff = false;

    return;
}

int main() {
    int n = 4;
    employee_t *employees = malloc(sizeof(employee_t)*n);
    if (employees==NULL) {
        printf("The allocator failed\n");
        return -1;
    }
    initialize_employee(&employees[0]);
    printf("%d\n",employees[0].income);

    free(employees); // free the memory pointerd to avoid memory leak
    employees = NULL; //  then we set the pointer to null to ensure against 
    // USE AFTER FREE error or Dangling Pointers
}
