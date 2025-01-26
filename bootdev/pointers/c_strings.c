/** C Strings
 *
 * since starting this course I've been skipping over and dancing
 * around this idea of char* strings. I haven't worried about this
 * char* stuff up to now, but now that I have a clearer idea of
 * pointers I can dive in headfirst.
 *
 * char* msg = "ssh terminal.shop for th best coffee";
 *
 * Above, msg is a pointer to the first character of the string
 * "ssh terminal.shop for the best coffee", which is a C string.
 *
 * C strings are:
 *      - How we rep text in C programs
 *      - Any number of characters (chars) terminated by a null char '\0'.
 *      - A pointer to the first element of a character array
 *
 * Its important to understand that most string manipulation in C
 * is done using pointers to move around the array and the null
 * terminator is critical for determining the end of the string. In
 * the example above, the string "ssh terminal.shop for the best coffee"
 * is stored in memory as an array of chars, and the null terminator
 * "\0" is automatically added at the end.
 *
 * C Strings Are Simple
 *      - Unlike other programming languages, C strings do not store
 *        their length
 *      - The length of a C string is determined by the position of
 *        the null terminator
 *      - Functions like strlen calculate the length of a string by
 *        iterating through the chars until the null terminator is
 *        encountered
 *      - This lack of length storage requires careful management
 *        to avoid issues such as buffer overflows and off-by-one
 *        errors during string operations.
 *
 * Pointers vs Arrays:
 * So I can declare strings in C using either pointers or arrays
 *
 * The output will be the same so which is better? let's break down
 * the memory in this example:
 *
 * the strcat func appends its second argument to the first arg.
 * In this case it appends "lang!" to "Snek" resulting in Hello Sneklang!
 *
 * First is probably 4 elements + the null character and then a bunch
 * of junk memory after the end of the string.
 *
 * second is just the chars and the null char. When appended though
 * we get Sneklang! and a bunch of garbage memory still there. strcat
 * uses the null terminator to know where to start concatenation,
 * but it doesn't know the length of the string or where to end.
 *
 * NOTE: since its an array of chars, we need to have enough memory
 * allocated in the first string to concatenate the second, thus the
 * need of an array larger than the string itself.
 *
 */
#include <stdio.h>
#include <string.h>

void concat_strings(char *, const char *);

int main(int argc, char const *argv[])
{
    // char str1[] = "Hi";
    // char* str2 = "Snek";
    // printf("%s %s\n",str1,str2);
    // printf("\n");

    char first[50] = "Snek";
    char *second = "lang!";
    strcat(first, second);
    printf("Hello, %s\n", first);
    printf("\n\n");

    // Assignment follows:

    char str1[100] = "Hello ";
    const char *str2 = "World";
    concat_strings(str1, str2);
    printf("Concatinated Word: %s\n", str1);

    return 0;
}

// void concat_strings(char* str1, const char* str2){
//     int null_index = 0;
//     for (int i = 0; i < sizeof(str1); i++) {
//         // interestingly the fix was matching 0 and not '\0'
//         if (str1[i] == 0) {
//             null_index = i;
//             break;
//         }
//     }

//     for (int i = 0; i < sizeof(str2); i++) {
//         str1[null_index] = str2[i];
//         null_index++;
//     }
//     str1[null_index] = '\0';
//     printf("%s\n",str1);

// }

void concat_strings(char *str1, const char *str2)
{
    char *end = str1;
    while (*end != '\0')
    {
        end++;
    }

    while (*str2 != '\0')
    {
        *end = *str2;
        end++;
        str2++;
    }

    *end = '\0';
}

// Strangely my solution worked the same as the one from Teej,
// but didn't pass all the tests and I don't know why. Also in Bootdev
// they used '\0' as a comparison of the null terminator but here 
// I get an error and had to use 0. And when I put them back in they
// work now 🤔🤔🤔🤔🤔🤔🤔


