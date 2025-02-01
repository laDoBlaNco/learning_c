/**Union:
 * 
 * Now that I understand clearly what structs and enums are, I can
 * dive into unions, which according to Teej are a combination
 * of them both
 * 
 * Unions in C can hold one of several types. They're like a 
 * less-strict sum type from the world of functional programming
 */

#include <stdio.h>

typedef union AgeOrName {
    int age;
    char *name;
} age_or_name_t;

// Assignment declarations
typedef enum {
    INTEGER,
    STRING,
} snek_object_kind_t;

typedef union {
    int v_int;
    char *v_string;
} snek_object_data_t;

typedef struct {
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

snek_object_t new_integer(int);
snek_object_t new_string(char *str);
void format_object(snek_object_t obj, char *buffer);

// so I'm basically saying that this type can hold either an int
// or a char*, but not both at the same time. Its either or. For
// both at the same time I would do the exact same but as a struct.
// I provide the list of possibilities so the C compiler knows the
// max potential memory requirement, and can account for that, being
// that my possible types won't be the same size. Then I can use it
// like this:
int main(int argc, char const *argv[])
{
    age_or_name_t lane = {.age = 29};
    printf("Age: %d\n",lane.age); // so an obvious question is what 
    // do I use (%d) if the type is a char* and not an it? Is there
    // a generic formatter?

    // Here where it gets interesting, as if it wasn't already 🤔, What
    // happens when I try to to access the name field (even though I set
    // the age field)? 
    // printf("name: %s\n",lane.name); // seg fault????

    // we get nothing? Or better yet we get undefined behavior which is
    // the root of vulnerabilities and hacks. A union only reserves enough
    // space to hold the largest  type in our union and then all of the
    // fields use that same memory. So when I set .age = 29, I'm writing
    // the integer rep of 29 to the memory of lane union, even though
    // it way more memory than needed. If I try to access .name, I read
    // from the same block of memory but but interpreting the bytes as
    // char *, which is why I get garbage resulting in a seg fault.
    // Simply put, setting a value of .age overwrites the value of .name
    // and vice versa, so I should only access the field I set, which again
    // makes this potentially dangerous.


    // Assignment: Create a snek_object_kind_t and use it to complete
    // the format_object function to switch on .kind of snek_object_t
    // writing a formatted string to the buffer.
    char buffer[100];
    snek_object_t i = new_integer(5);
    format_object(i,buffer);
    printf("%s\n",buffer);

    return 0;
}

// function definitions
snek_object_t new_integer(int i) {
    return (snek_object_t){
        .kind = INTEGER,
        .data = {.v_int = i}
    };
}

snek_object_t new_string(char *str) {
    // note we'll learn how to copy this data later
    return (snek_object_t){
        .kind = STRING,
        .data = {.v_string = str}
    };
}

void format_object(snek_object_t obj, char *buffer) {
    switch(obj.kind) {
        case INTEGER:
            sprintf(buffer,"int:%d",obj.data.v_int);
            break;
        case STRING:
            sprintf(buffer,"string:%s",obj.data.v_string);
            break;
    }
}