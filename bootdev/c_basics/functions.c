/**Functions:
 * 
 * In C functions specify the types for their argumetns and return 
 * value.
 * 
 * float add(int x, int y){
 *      return (float)(x+y);
 * }
 * 
 *  - The first type, float is the return type
 *  - add is the name of our function
 *  - int x, int y are the arguments to the function, and their
 *    types are specified
 *  - x + y adds the two arguments together
 *  - (float) casts teh result to a float
 *      - We'll talk more about what cast means later, and the rules
 *        for casting to and from certain types
 *      - The simple version is that it instructs C to treat the result
 *        of (x + y) as a float.
 * 
 * Here's how we call the function
 * 
 * It's nice that C functions enforce returning the same type from 
 * all return statements, isn't it? In Python, it can be a pain to 
 * realize that a function returns different types depending on the
 * path it took.
 */
#include <stdio.h>

float add(int,int); // declaration for the add function
void init_sneklang(int,int);
int max_sneklang_memory(int,int);

int main(int argc, char const *argv[])
{
    float result = add(10,5);
    printf("result: %f\n",result);
    printf("\n");

    init_sneklang(4, 512);
    init_sneklang(8, 1024);
    init_sneklang(16, 2048);
    return 0;
}

float add(int x, int y){
    return (float)(x+y);
}

void init_sneklang(int max_threads, int memory_per_thread) {
  printf("Initializing Sneklang\n");
  printf("Max threads: %d\n", max_threads);
  printf("Memory per thread: %d\n", memory_per_thread);
  int max_memory = max_sneklang_memory(max_threads, memory_per_thread);
  printf("Max memory: %d\n", max_memory);
  printf("====================================\n");
}

int max_sneklang_memory(int num1, int num2){
    return num1 * num2;
}