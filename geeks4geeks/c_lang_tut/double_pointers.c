/** C - Pointer to Pointer (Double Pointers)
 * 
 * In C, double pointers are those pointers which store the address
 * of another pointer. The first pointer is used to store the address
 * of a variable and the second pointer is used to store the address
 * of the first pointer.  That is why they are also known as
 * pointer to pointers
 * 
 * Syntax of a Double Pointer:
 * The syntax to use double pointers can be divided in 3 parts: 
 *  1. Declaration: 
 *     A double pointer can be declared similar to a single pointer
 *     The difference is we have to place an additional '*' before
 *     the name of the pointer
 *      ▫️ type **name;
 * 
 *     Above is the declaration of the double pointer with some name
 *     to the given type. 
 * 
 *  2. Initialization: 
 *     The double  pointer stores the address of another pointer to 
 *     the SAME type. 
 *      ▫️ name = &single_ptr;     // After declaration we don't use **name if
 *                                // we've already declared type **name;
 *      ▫️ type **name = &single_ptr;  // With the declaration altogether
 * 
 *  3. Dereferencing: 
 *     To access the value pointed to by the double pointer, we have to
 *     use the dereference operator * two times (once to get to the first
 *     pointer and second to get to the first pointer's value)
 *      ▫️ *name;   // Gives you the address of the single pointer
 *      ▫️ **name;  // Gives you the value of the variable it points to
 * 
 * https://media.geeksforgeeks.org/wp-content/uploads/20241230181312080795/double-pointers-in-c.webp
 * 
 * In C, a double pointer behaves similarly to a normal pointer. So,
 * So the SIZE OF THE DOUBLE-POINTER variable is always equal to the
 * normal pointers i.e. only depending on the operating system and 
 * CPU arch. 
 *      ▫️ 8 bytes for 64-bit 
 *      ▫️ 4 bytes for 32-bit
 * 
 * Examples of Double Pointers:
 */
#include <stdio.h>
#include <stdlib.h>

void print(char**,int);

int main(int argc, char const *argv[])
{

    /**
     * In this code, ptr1 is a pointer that stores the address of
     * the integer variable var. ptr2 is a double pointer that stores
     * the address of the pointer pt1. **ptr2 dereferences ptr2 to get
     * the value of ptr1 (which is the address of var) and then 
     * dereferences that address to get the value of var itself. 
     */
    // a var
    int var = 10;

    // pointer to int
    int *ptr1 = &var;

    // pointer to pointer (double pointer)
    int **ptr2 = &ptr1;

    printf("var: %d\n",var);
    printf("*ptr1: %d\n",*ptr1);
    printf("**ptr2: %d\n",**ptr2);

    // Find the size of a double pointer
    int a = 5;
    int *ptr = &a;
    int **d_ptr = &ptr;
    printf("\n%zu bytes\n",sizeof(d_ptr));

    /**
     * Below a 2D array is an array where each element is essentially
     * a 1D array. This can be implemented using double pointers. 
     * The double pointer points to the first element of the 2D array
     * and each pointer it references points to a dynamically allocated
     * 1D array using malloc(). I think my issue is around the understanding
     * of allocating for a double pointer with malloc or not. 🤔
     */
    // Create a Dynamic 2d Array
    int m = 2, n = 3;
    int **arr;
    arr = (int**)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = i * n + j + 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n\n");
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    /**
     * Array of strings are generally stored as array of pointer to
     * strings. This can be passed using double pointers to function
     */
    char *arr2[10] = {"Geek", "Geeks", "Geekfor"};
    print(arr2,3);
   


    return 0;
}

void print(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", *(arr + i)); // the arr+i moves the pointer along
        // and *() dereferences it
    }
}

/**
 * Application of Double Pointers in C
 * 
 * Following are the main uses of pointer to pointers in C
 *  ▫️ They are used in the dynamic memory allocation of multidimensional
 *    arrays
 *  ▫️ They can be used to store multilevel data such as the text document
 *    paragraph, sentences, and word semantics
 *  ▫️ They are used in data structures to directly manipulate the address
 *    of the nodes without copying
 *  ▫️ They can be used as function arguments to manipulate the address 
 *    stored in the local pointer
 * 
 * Multilevel Pointers in C
 * Double pointers are not the only multilevel pointers supported by 
 * the C language. What if I want to change the value of a double pointer?
 * In this case, I can use a triple pointer, which will be a pointer 
 * to a pointer to a pointer i.e., ***t_ptr.
 *  ▫️ int ***ptr3;
 *  ▫️ int ****ptr4; 
 *  ▫️ ... etc
 * 
 * Similarly to change the value of a triple pointer I can use a
 * pointer to a pointer to a pointer to a pointer (4 level pointer).
 * In other words, I can say that to change the value of a "level -- x" 
 * variable I can use a "level -- x+1" pointer. 
 * 
 * BE CAREFUL WITH THE NUMBER OF LEVELS 
 */
