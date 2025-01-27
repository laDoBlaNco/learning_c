/** Mutal Structs
 * 
 * There is also another need and use for forward declarations, when I have 
 * two structs that reference each other (a circular reference). For 
 * example a Person has a Computer and a Computer has a Person
 * 
 * The assignment is to do the same for to structs: Employee and Department
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Computer computer_t;
typedef struct Person person_t;
typedef struct Employee employee_t;
typedef struct Department department_t;

// strange that I still need to use 'typedef' in the forward declaration
// even though its not in the actual def
struct Person {
    char *name;
    computer_t *computer;
};

struct Computer{
    char *brand;
    person_t *owner;
};

typedef struct Employee {
    int id;
    char *name;
    department_t *department;
} employee_t;

typedef struct Department {
    char *name;
    employee_t *manager;
} department_t;

employee_t create_employee(int,char*);
department_t create_department(char*);
void assign_employee(employee_t *, department_t *);
void assign_manager(department_t *, employee_t *);

int main(int argc, char const *argv[]) {
    employee_t emp = create_employee(2,"CEO Dax");
    department_t dept = create_department("C Suite");
    assign_employee(&emp,&dept);
    printf("Employee Name: %s\n",emp.department->name);

    return 0;
}

employee_t create_employee(int id, char *name) {
    employee_t emp = {
        .id = id,
        .name = name,
        .department = NULL,
    };
    return emp;
}

department_t create_department(char *name) {
    department_t dept = {
        .name = name,
        .manager = NULL,
    };
    return dept;
}

void assign_employee(employee_t *emp, department_t *department) {
    emp->department = department;
}

void assign_manager(department_t *dept, employee_t *manager) {
    dept->manager = manager;
}
