/**The Stack
 * 
 * Remember how memory is basically just a giant array of bytes
 * with address at different offsets?
 * 
 * While that's true there are also some additional structure. The
 * memory is devided into two may regions:
 *      🔹 stack
 *      🔹 heap
 * 
 * The stack is where local variables are stored. When a function
 * is called a new STACK FRAME is created in memory to store the
 * function's parameters and local variables. When the function
 * returns, its entire stack frame is deallocated or popped off the
 * stack. 
 * 
 * The stack is aptly named: it is a stack (LIFO) data structure
 * of memory frames. Each time a function is called a new frame
 * is pushed onto the stack, including 'main'. When a function 
 * returns, its frame is popped off the stack. 
 * 
 * For example:
 * with the function below if I call 'create_typist(1)', before the
 * call, the stack memory might look like this: 
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/Ir7pLV9.png
 * 
 * An array of contiguous memory with its addresses every 4 bytes. 
 * Once called, the STACK POINTER is moved to make room for: 
 *      🔹 The return address (to pick up execution after the function
 *         returns)
 *      🔹 Arguments to the function
 *      🔹 Local variables in the function body
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/dA4uooG.png
 * 
 * the local variables are stored in the stack frame: 
 * https://storage.googleapis.com/qvault-webapp-dynamic-assets/course_assets/hVO0TxY.png
 * 
 * When the function returns, the stack frame is deallocated by resetting the
 * stack pointer to where the frame begins.
 * 
 * Assignment: 
 *      1. Run the code in its current state
 *      2. Update 'where' print_message_two and print_message_three 
 *         are called from so that all three of the functions use
 *         the same stack space
 */
#include <stdio.h>

void create_typist(int uses_nvim);
// assignment declarations:
void print_message_one();
void print_message_two();
void print_message_three();
void print_stack_pointer_diff();

int main(int argc, char const *argv[])
{
    
    // assignment - calling them from the functions  creates the
    // new stack frame, but calling them sequentially from main
    // simply runs and pops and they all end up running in the same 
    // frame sequentially.
    print_message_one();
    print_message_two();
    print_message_three();

    return 0;
}

void create_typist(int uses_nvim)
{
    int wpm = 150;
    char name[4] = {'t','e','e','j'};

}

void print_message_one() {
    const char *message = "Dark mode?\n";
    print_stack_pointer_diff();
    printf("%s\n", message);
    // print_message_two();
}

void print_message_two() {
    const char *message = "More like...\n";
    print_stack_pointer_diff();
    printf("%s\n", message);
    // print_message_three();
}

void print_message_three() {
    const char *message = "dark roast.\n";
    print_stack_pointer_diff();
    printf("%s\n", message);
}

void print_stack_pointer_diff() {
    static void *last_sp = NULL; // stack null pointer
    void *current_sp; // creating a null pointer
    current_sp = __builtin_frame_address(0); // ??? not sure what this is
    long diff = (char *)last_sp - (char *)current_sp;
    // as I learned with null pointers we need to cast them on use
    if (last_sp == NULL) {
        last_sp = current_sp;
        diff = 0;
    }

    printf("---------------------------------\n");
    printf("Stack pointer offset: %ld bytes\n", diff);
    printf("---------------------------------\n");
}
