/**Sizeof Enum
 * 
 * The same sizeof operator that we've talked about works on 
 * enums.
 * 
 * Generally, enums in C are the same size as the int. However
 * if an enum value exceeds the range of an int (which as I learned
 * is the limit of 1 word size 4 or 8 bytes), the C compiler will
 * use a larger integer type to accommodate the value, such as an
 * unsigned int or a long
 * 
 *      🔹 unsigned int doesn't represent negative numbers, so it
 *         can represent larger positive numbers.
 *      🔹 long is just a larger integer type than int, so it can
 *         represent larger numbers. 
 * 
 * Just Fancy Integers
 * Enums are often used to represent the possibilities in a set. 
 * For example: 
 *      🔹 SMALL = 0
 *      🔹 MEDIUM = 1
 *      🔹 LARGE = 2
 *      🔹 EXTRA_LARGE = 3
 * 
 * The program proabably cares a lot abot which size a variable 
 * represents, but it probably doesn't care that SMALL happens to
 * be 0 under the hood. From the compiler's perspective, enums
 * are just fancy integers. 
 * 
 * Assignment
 * At the start of main(), print the size of the two enums defined
 * in main.c:
 */

#include <stdio.h>

typedef enum {
    BIG = 123412341234,
    BIGGER,
    BIGGEST,
} BigNumbers;

typedef enum {
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_NOT_FOUND = 404,
    HTTP_I_AM_A_TEAPOT = 418,
    HTTP_INTERNAL_SERVER_ERROR = 500,
} HttpErrorCode;

int main(int argc, char const *argv[])
{
    printf("The size of BigNumbers is %zu bytes\n",sizeof(BigNumbers));
    printf("The size of HttpErrorCode is %zu bytes\n",sizeof(HttpErrorCode));

    return 0;
}
// Remember that %zu is the format specifier for size_t which is the
// return value for sizeof()