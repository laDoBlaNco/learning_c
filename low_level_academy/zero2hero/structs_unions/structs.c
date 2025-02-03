#include <stdio.h>
#include <stdbool.h>

#define MAX_IDS 32
#define MAX_EMPLOYEES 1000

/**Structures:
 * In our previous lessons, we talked about how to organize data that was
 * of the same type together into arrays which are contiguous blocks of memory.
 * giving me the power to store and modify a lot of data at the same time
 * programatically. But what happens when I have to use a block of memory that 
 * contains different types of fields, like maybe name, income, etc. 
 * 
 * enter stage right -> structures
 * A structure is a block of memory that contains variables of different or same
 * types that represent a logical representation of memory. 
 * 
 * I can create a struct in the following manner:
 */

struct my_struct {
    int i;
    char c;
};

// on boot-dev Teej showed a slighly different syntax where we add the name_t
// at the end, but here it looks even easier, so not sure if its better or not
struct employee_t {
    // this reminds me more of Go and Odin
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    // interesting on geeksforgeeks i learned that there is on 'bool' type 
    // built-in for C. I had to use the <stdbool.h> file
    bool ismanager;
};

// before, we created arrays, if a structure is a type, can we create multiple
// structures together in an array? Of course

int main(int argc, char const *argv[])
{
    struct my_struct my_structs[10];
    // not sure how to print this to look at it. Maybe later

    // For example:
    // struct employee_t Fred;
    // Fred.income = 100.00;
    // Fred.ismanager = true;

    // but we can also create arrays of structs
    struct employee_t employees[MAX_EMPLOYEES];

    for (int i=0;i < MAX_EMPLOYEES;i++) {
        employees[i].income = 0;
        employees[i].ismanager = false;
        employees[i].id = i;
        
        printf("ID: %d\nIncome: %f\nManager?: %s\n\n",
            employees[i].id,employees[i].income,employees[i].ismanager ? "true":"false");
    }

    // and it worked !
    

    return 0;
}

