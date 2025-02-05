/**
 * Array of Pointers
 * 
 * I just had to start this one over again cuz it wasn't getting
 * into my brain. So let's try it again. Making an array of integers
 * on the heap is pretty simple. 
 * 
 * Again this is an array of integers on the heap.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token {
    char *literal;
    int line;
    int column;
} token_t;

token_t **create_token_pointer_array(token_t *tokens, size_t count);


int main(int argc, char const *argv[])
{
    // remember that malloc returns a void pointer so
    int *int_array = (int *)malloc(sizeof(int) * 3);
    int_array[0] = 1;
    int_array[1] = 2;
    int_array[2] = 3;

    // But we can also make an array of pointers! It's quite common
    // to do this in C, especially considering that strings are 
    // just pointers to chars
    char **string_array = malloc(sizeof(char *) * 3);
    string_array[0] = "foo";
    string_array[1] = "bar";
    string_array[2] = "baz";

    // Assignment
    token_t token = {"hello",1,1};
    token_t **result = create_token_pointer_array(&token,1);

    return 0;
}

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
    token_t **token_pointers = malloc(count * sizeof(token_t*));
    if (token_pointers == NULL) {
        exit(1);
    }
    for (size_t i = 0; i < count; ++i) {
        // so I had to do was use this same loop to create a tokens_pointers
        // entry in malloc for each of the ones in stack
        token_pointers[i] = (token_t*)malloc(sizeof(token_t));
        if (token_pointers[i] == NULL) {
            exit(1);
        }
        token_pointers[i]->literal = tokens[i].literal;
        token_pointers[i]->line = tokens[i].line;
        token_pointers[i]->column = tokens[i].column;
    }
    return token_pointers;
}

