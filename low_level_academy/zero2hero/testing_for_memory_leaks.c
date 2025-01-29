/**Testing for Memory Leaks
 * 
 * So in the previous lession, I talked about how memory can be taken
 * from system using calls to an allocator, like malloc for example, But
 * also discussed how bad things can happen if I don't free up the memory
 * after.
 * 
 * In this section I'll discuss how to check my code for memory leaks using
 * a tool call valgrind.
 * 
 * Valgrind is program that wraps the calls to malloc and free, tags them
 * and checks to see where memory is leaked or potentially leaked.
 * 
 * First we set it up:
 * Start by compiling with debug symbols in the code
 *      gcc -o program code.c -g
 * 
 * The -g adds debug symbols to the code. Then we simply run:
 *      valgrind --leak-check=full ./program
 * 
 * Valgrind will run the code and provide a report of what memory didn't
 * get freed, and where the allocation happened. 
 * 
 * Code Coverage:
 * NOTE: I need to write tests to make the code execute lines that allocate
 * from the heap to use valgrind correctly. If the code never allocates
 * from the heap in the test case, it'll never see the memory leak.
 * 
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000;

struct employee_t {
    int id;
    int income;
    bool staff;
};

int initialize_employee(struct employee_t *e) {
    static int num_employees = 0;
    num_employees++;

    e->id = num_employees;
    e->income = 0;
    e->staff = false;

    return num_employees;
}

int main(){
    // this value came from the database header
    int n = 4;

    struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
    if (employees == NULL) {
        printf("The allocator failed\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        int id = initialize_employee(&employees[i]);
        printf("New employee, ID is %d\n", id);
    }

    free(employees);
    employees = NULL;
}

// using valgrind again reminds me of some of the stuff I did with
// Go and the stack trace reports I would run and study there. 