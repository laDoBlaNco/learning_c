/**Void:
 * 
 * In C there's a special type used for function signatures:
 * 'void' There are two primary ways I'll use void
 * 
 * to explicitly state that a function takes no arguments
 * int get_int(void){
 *      return 42;
 * }
 * 
 * When a function doesn't return anything
 * void print_int(int x){
 *      printf(This is an int; %d\n",x);
 * }
 * 
 * It's important to ote that void in C is not like None in Python
 * It's not a value tht can be assigned to a variable. Its just a 
 * way to say that a function doesn't return anything or doesn't 
 * take any arguments. 
 */
#include <stdio.h>

 int get_int(void){
    return 42;
 }

 void print_int(int x){
     printf("This is an in: %d\n",x);
 }

 int main(int argc, char const *argv[])
 {
    printf("%d\n",get_int());
    print_int(66);
    return 0;
 }
 