/**The C String Library
 * 
 * The c standard library provides me with a comprehensive set of 
 * functions to manipulate strings in the <string.h> file.
 * 
 * let's see some of them
 * 
 */
#include <stdio.h>
#include <string.h>

typedef struct
{
    size_t length;
    char buffer[64];
} TextBuffer;

int smart_append(TextBuffer*,const char*);

int main(int argc, char const *argv[])
{
    // strcpy; copies a string to another
    char src[] = "Hello";
    char dest[6];
    strcpy(dest,src); // I feel like this syntax is a bit backwards 
    // just like Go's, better said Go got it from here
    printf("%s\n",dest);

    // strcat - concat strings remember I need to allocate my own memory in C
    char dest2[12] = "Hello";
    char src2[] = " World!";
    strcat(dest2,src2);
    printf("%s\n",dest2);

    // strlen; Returns the length of a string (excluding the null term.)
    char str[] = "Hello";
    size_t len = strlen(str);
    printf("The string has a length of %zu\n",len);

    //strcmp: compares two strings lexicographically (neg < 0 < pos) 
    char str1[] = "Hello";
    char str2[] = "World";
    int result = strcmp(str1,str2);
    printf("The result of this string comparison: %d\n",result);

    // strncpy: Copies a specified number of characters from one string
    // to another
    char src3[] = "Hello";
    char dest3[6];
    strncpy(dest3,src3,3);
    // dest now contians "Hel"
    dest3[3] = 0;
    // ensure the null termination
    printf("%s\n",dest3);

    // strncat: concatenates a specified number of chars from one string
    // to another
    char dest4[12] = "Hello";
    char src4[] = " World";
    strncat(dest4,src4,3);
    printf("%s\n",dest4);

    // strchr: Finds the first occurence of a char in a string
    char str3[] = "Hello";
    char *pos = strchr(str3,'l');
    printf("We now have pointer %p to %c\n",pos,*pos); // this could be helpful with some
    // of the DSA work in C

    // strstr Finds the first occurence of a substring in a string
    char str4[] = "Hello world";
    char *pos2 = strstr(str4,"world");
    printf("Now we hae a pointer %p to %c\n",pos2,*pos2);

    // Assignment starts here:
    printf("\n\nAssignment:\n");

    TextBuffer my_buffer;
    my_buffer.length = 21;
    strcpy(my_buffer.buffer,"This is a long string");
    printf("Current Buffer: %s\n",my_buffer.buffer);
    const char* my_src = " that will fill the whole buffer and leave no space for some of the chars.";
    int my_result = smart_append(&my_buffer,my_src);
    printf("Updated Buffer: %s\n",my_buffer.buffer);
    printf("Updated Length: %zu\n",my_buffer.length);
    printf("Return Result: %d\n",my_result);

    return 0;
}

int smart_append(TextBuffer *dest, const char* src){
    if (dest == NULL || src == NULL) return 1;

    const int MAX_BUFFER = 64;
    size_t len = strlen(src);
    int available_space = MAX_BUFFER - (dest->length + 1);

    if (strlen(src) > available_space) {
        strncat(dest->buffer,src,available_space);
        // dest->buffer[63] = 0; // strncat does this
        dest->length = MAX_BUFFER - 1;
        return 1;
    } else {
        strcat(dest->buffer,src);
        int new_len = dest->length + len;
        dest->length = new_len;
        // dest->buffer[new_len] = 0; // strcat does this
        return 0;
    }

}
// One key note from this lesson is that the C string manip functions
// already account for the null terminator so I don't have to, but in 
// all other situations I need to account for adding it back in. Despite
// that I need to account for it when dealing with lengths and allocating
// for space for concatenation and copying.
