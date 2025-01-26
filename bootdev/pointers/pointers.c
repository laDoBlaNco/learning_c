/**Pointers:
 * 
 * Now I get into pointers. There have been pleny of jokes and 
 * comments around how its impossible to learn pointers. Well
 * that's garbage. 
 * 
 * In fact, now that I understanding the basics of how memory is laid out
 * a lot of the mystery behind pointers is gone. Put simply, A POINTER
 * IS JUST A VARIABLE THAT STORES A MEMORY ADDRESS. Its called a pointer
 * because that variable 'points' to the address of a varible, which 
 * in turn stores the actual data held in that variable.
 * 
 * Syntax/Semantics:
 * A pointer is declared with an asterisk (*) after the type. Its 
 * actually part of the type name: int *
 * 
 *      int age = 48;
 *      int *pointer_to_age = &age;  -- note the address_of_operator
 * 
 * Remember to get the address of a variable so that we can store it
 * in a pointer variable, I can use the address-of-operator (&)
 */