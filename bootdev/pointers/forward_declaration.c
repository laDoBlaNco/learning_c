/**Forward Declaration
 * 
 * Now sometimes I might have a struct that wll need to ref itself
 * or be used recursively. For example when I start working with
 * DSA in C I'll probably need to start working with types such as
 * these. 
 * 
 * the problem arises that node_t isn't yet defined, so the compiler
 * will complain. To fix this I can add a forward declaration. Which
 * looks like a simple typedef declaration the same as we do function
 * declarations
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declaration for types seem to be the same as function declarations
typedef struct Node node_t;

// This looks like a linked list node
typedef struct Node {
    int value;
    node_t *next;
} node_t;

// It MUST GO ABOVE THE ACTUAL TYPE DEFINITION which makes sense if the
// error is in that definition for not finding the type name.
typedef struct SnekObject snekobject_t;

// assignment type snekobject_t
typedef struct SnekObject {
    char *name;
    snekobject_t *child;
} snekobject_t;

snekobject_t new_node(char *);

int main(int argc, char const *argv[]){
    // This is all for the assignment, see the error ("uknown type name") and fix it
    // using a forward declaration for the snekobject_t

    // we start creating our var type snekobject_t
    snekobject_t node = new_node("root");
    return 0;
}

snekobject_t new_node(char *name) {
    snekobject_t node = {
        .name = name,
        .child = NULL,
    };
    return node;
}

// Pretty simple concept. Just like we do function declarations we need to do
// type declarations (forward declararations), especially if we need to refer
// This is probably true for functions when we have recursive functions as well.
