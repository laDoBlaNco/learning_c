/**Arrays Decay to Pointers
 * 
 * So arrays are LIKE pointers, but they aren't exactly the same
 * Arrays allocate memory for all their elements, whereas pointers
 * just hold the address of a memory location. In many contexts, 
 * arrays decay to pointers, meaning the array name becomes "just" 
 * a pointer to the first element of the array, which is what I've
 * seen so far.
 * 
 * When arrays decay
 * Arrays decay when used in expressions containing pointers. so if
 * we use pointer semantics with arrays, then they decay to simple
 * pointers. 
 * 
 * Also if they are passed to functions...so they actually decay
 * quite often in practice, which is why most times I will see them
 * as just pointers. That's why I can't pass an array to a function
 * by value like a struct; instead, the array name decays to a 
 * pointer automatically. 
 * 
 * But then why when I use an actual pointer on a struct I can't get
 * the same behavior of inline mutablility on the struct??? 🤔🤔🤔
 * 
 * When do arrays not decay?
 *      - sizeof operator: Returns the size of the entire array
 *        not just the size of a pointer. 
 *      - & Operator: Taking the address of an array with &arr gives
 *        me a pointer to the whole array, not just the first element
 *        The type of &arr pointer is pointer to array int(*)[5] 
 *        for a array of 5 elements rather than pointer to int*. 
 *      - Initialization: When an array is declared and initialized 
 *        it is fully allocated in memory and doesn't decay to a ptr.
 * 
 * So in the end an array decays (becomes a simple pointer) when passed
 * to a function, or used in the context of a pointer with * either in
 * typing or dereferencing. But not with & in getting the address of 
 * the array itself, Initialization or with sizeof.
 * 
 */
#include <stdio.h>

void core_utils_func(int*);

int main(int argc, char const *argv[])
{
    int arr[5];
    int* ptr = arr;  // 'arr' decays to 'int*'
    int value = *(arr+2); // 'arr' decays to 'int*'

    //====================================================
    // Assignment: Complete the core_utils_func to print:
    // sizeof core_utilization in core_utils_func: X
    int core_utilization[] = {43, 67, 89, 92, 71, 43, 56, 12};
    // NOTE: I didn't notice this before by the length of an array even 
    // when its not decayed isn't just using sizeof(array). Remember that 
    // sizeof gives us the amount of bytes in total memory, not taking
    // into consideration the type size. This means the same way we need
    // to malloc(count * sizeof(T)). To get the length of the array we need
    // to go backwards with (sizeof(array) / sizeof(array[0])) dividing the
    // full size of the array (in this case 32 bytes) by the sizeof one element
    // (in this case 4 for int) which gives us a length of 32 / 4 = 8
    int len = sizeof(core_utilization) / sizeof(core_utilization[0]);
    printf("sizeof core_utilization in main: %zu\n", sizeof(core_utilization));
    printf("len of core_utilization: %d\n", len);
    core_utils_func(core_utilization);    

    return 0;
}

void core_utils_func(int core_utilization[])
{
    printf("sizeof core_utilzation in core_utils_func: %zu\n",sizeof(core_utilization));
}

// and I get a warning from the compiler because of the decaying. but NOTE:
// because of being in the function I get a sizeof result of a normal pointer
// and not the array size as I do on the outside in main which is 32 (8 * 4)