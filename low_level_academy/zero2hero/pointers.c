/**Pointers. 
 * Pointers scare a lot of people. Something about them is just hard to grasp
 * for new devs or its just the bad reputation that they have when talking about 
 * memory management under the hood. 
 * 
 * A pointer is just a variable who's value equals the address of another variable..
 * that's it. Nothing scary about it. 
 * 
 * How do I create them?
 * To make a variable, first I need another variable that I want to point to. 
 * 
 */

#include <stdio.h>
#include <stdbool.h>

int x = 3;

struct employee_t {
    int id;
    float income;
    bool staff;
};

// To create a pointer that points to x, all I need to do is create a variable
// and set its value equal to the ADDRESS of x. We do this with our pointer semantics
// (* and &) operators
int *px = &x;  // The * char notes that the type is a pointer, so int * is part of the
// type.
// The & char is what is getting the address of x and puts it in px.

// So now how do we use pointers. To use a pointer, all I have to do is "dereference"
// it. this simply means putting the * on the name of the pointer again but this time
// without/not as the type but in order to access the value at that address location.
// Normall in other scopes.
void initialize_employee(struct employee_t *e);


int main(int argc, char const *argv[])
{
    printf("%d\n",*px);
    printf("%p\n",px);

    // So let's get a bit more realistic here using our struct type employee_t
    struct employee_t Ralph;

    // setting the default values for Ralph
    // Ralph.id = 1;
    // Ralph.income = 50000;

    // now we can say
    initialize_employee(&Ralph);
    printf("%d\n",Ralph.id);
    printf("%f\n",Ralph.income);


    return 0;
}

void initialize_employee(struct employee_t *e)
{
    // first time seeing this pointer syntax which is probably where the PHP 
    // class syntax came from
    e->id = 66;
    e->income = 100000;
    e->staff = false;

    return;
}