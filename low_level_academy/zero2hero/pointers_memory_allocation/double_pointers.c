/**Pointers to Pointers
 * 
 * So pointers to pointers is the "point" in learning C that most
 * people get tripped up as its another layer of abstraction and
 * well...pointing. And people don't really understand why its exists
 * or why one would need this. But it does get important. It makes
 * me kinda think of PHP and its $$vars. But let's see.
 * 
 * pointer = address of a variable
 * double pointer = address of the address of a variable.  But why???
 * 
 *      int i;  -- space on the stack that contains the int value
 *      int *pi = &i;  -- space on the stack that contains the address of i
 *      int **ppi = &pi -- space on the stack that contains the address of pi
 * 
 *  - Used to update pointers outside of function scope
 *      int *data = malloc(BIG_SIZE); -- if this was inside of a function
 *      But now I want to either update it or use it outside of that function
 *      I need to pull it out of that scope without actually returning it. 
 *      I get access to it and other pointers by passing around the pointer
 *      to the pointer
 * 
 *      status_t foo (int **data_out) {
 *          ...
 *          *data_out = malloc(BIG_SIZE);
 *          // note how the arg is **data_out and through that we are
 *          // accessing *data_out. Its  like giving us a portal from
 *          // one scope to another without moving the actual value or
 *          // a copy of the object around. This seems like the beginnings
 *          // of networking in C. 🤔🤔🤔
 *      }
 * 
 * The example below helps me to see and understand double pointers by
 * updating a pointer via 'realloc' in a function called foo. Remember 
 * that a double pointer is just a pointer that points to a pointer. In
 * memory management, double pointers are particularly useful for 
 * functions that need to modify the original pointer, such as allocating
 * or resizing dynamic memory. In my mental model I like to think of a
 * tunnel or portal from one function scope to the other. So the first 
 * * in **ptr accesses the portal and the next * in *ptr accesses the
 * value. So the *s are like doors leading to our value that we want to
 * access. 
 * 
 * Basic Concept again:
 *      pointer: a var that holds the address of another variable
 *      double pointer: a var that holds the address of a pointer
 * 
 * In the example below I want to create a function foo that resizes
 * an array using realloc. The function accept a double pointer to 
 * the array so that it can modify the original pointer
 *      
 */ 
#include <stdio.h>
#include <stdlib.h>

// first I create my return type (enum) of good or bad result
typedef enum {
    STATUS_GOOD,
    STATUS_BAD,
} status_t;

// then I'll create the actual function here instead of a func declaration
// since its only one func and I know what I want already ... 
// on another note: https://www.freecodecamp.org/news/how-to-use-functions-in-c/#:~:text=Declaring%20a%20function%20in%20C,it%20is%20specified%20or%20implemented.
// Declaring a function in C informs the compiler about the presence of a function
// without giving implementation details in the moment. This enables the function
// to be called by other sections of the software before it is specified or
// implemented. 

// status_t foo(int **arr, size_t new_size) {
//     // that **arr arg is my portal to *arr
//     int *temp = realloc(*arr,new_size * sizeof(int));
//     if (temp == NULL) {
//         // handle realloc failure - same as when using malloc
//         printf("Memory reallocation failed\n");

//         return STATUS_BAD;
//     }
//     *arr = temp;  // go through our portal to dereference our target value
//     return STATUS_GOOD;
// }

// The code on the page was refactored for security in the video. This new 
// version includes the removal of dangling pointers and freeing malloc
status_t foo(int **data, int len) {
    int *temp = NULL;
    temp = realloc(*data, len);

    if (temp == NULL) {
        *data = NULL; // this doesn't seem right, why destroy *data, I guess since 
        // this failure crashes the program we are just destroying it here, but 
        // still doesn't seem right. 
        return STATUS_BAD;
    }

    *data = temp;
    return STATUS_GOOD;
}


// NOTE: so what if I have two pointers pointing to the same pointer??? Race conditions?

// int main(){
//     size_t initial_size = 5;
//     size_t new_size = 10;


//     // remember that malloc gives me a pointer to the new memory
//     int *arr = malloc(initial_size * sizeof(int));
//     if (arr == NULL) {
//         printf("Memory allocation failed\n");
//         return 1;  // basic early returns like in Go
//     }

//     // Initialize the array
//     for (size_t i = 0; i < initial_size; i++) {
//         arr[i] = i;
//     }

//     // print the initial array
//     printf("Initial Array:\n");
//     for (size_t i = 0; i < initial_size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // call foo to resize the array
//     if (STATUS_BAD == foo(&arr, new_size)) {
//         printf("uh oh");
//         return -1; // again very similar to dealing with errors in Go
//     }

//     // Initialize the new part of the array
//     for (size_t i = initial_size; i < new_size; i++) {
//         arr[i] = i;
//     }

//     // Print the resized array
//     printf("Resized array:\n");
//     for(size_t i = 0; i < new_size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // don't forget to free the memory
//     free(arr); 
//     // Do I need to free the original malloc??? since it was in an
//     // function???  Low Level didn't do it
// }

// The refactored main
int main(){
    int *first = malloc(64);
    if (STATUS_BAD == foo(&first,128)) {
        printf("uh oh\n");
    }

    return 0;
}

// CONCLUSION: Double pointers are essential in C for functions that
// need to modify the original pointer, such as those that allocate or
// resize dynamic memory. This lesson demonstrated how to use double 
// pointers with realloc to resize an array in a function.


