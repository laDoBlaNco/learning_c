/**Static Memory Allocation
 * 
 * Sometimes we want data to exist in the scope of the lifetime of
 * our entire program. For example, what if we want to track the amount 
 * employees that have been initialized in our database so far? We have
 * two options; global and static variables.
 * 
 * Static Vars:
 * A static variable is a variable that exists in a static lifetime, but does
 * not have a global scope. By creating a static var I am able to create
 * vars that out live the lifetime of the function call and track data
 * over multiple calls to the same function.
 * 
 * Below i is set to zero the first time the function is ran. When this 
 * happens the var's data is actually stored not on the stack, but somewhere
 * in the data section of the program that is running. Later calls to my_static_test
 * will increase that var everytime
 * 
 * A use case would be for our dbase to track how many times a particular function
 * is called.
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

// int g_num_employees = 0; // typically I don't want to use global variables because
// especially when we get into multi-threaded code there's no way to ensure that
// we aren't trying to mutate this var from multiple functions

struct employee_t {
    int id;
    int income;
    bool staff;
};

int initialize_employee(struct employee_t *e) {
    static int num_employees = 0; // with the static var, this is place in the
    // data section of the ELF, not on the global stack. But this way other
    // functions can't touch this and there aren't any race conditions
    num_employees++;

    e->id = num_employees;
    e->income = 0;
    e->staff = false;

    return num_employees;
}

int my_static_test(){
    static int i = 0;
    i++;
}

int main(){
    int n = 4;

    struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
    if (employees == NULL) {
        printf("The allocator failed\n");
        return  -1;
    }

    for (int i = 0; i < n; i++){
        int id = initialize_employee(&employees[i]);
        printf("New Employee, ID is %d\n",id);

    }

    free(employees);
    employees = NULL;

}