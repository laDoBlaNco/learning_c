/** Const in C
 *
 * The const keyword in C is used to declare a variable as read-only,
 * meaning its value cannot be changed during program execution. When
 * a variable is declared wit hthe const keyword, its value cannot be
 * modified after initialization
 */
#include <stdio.h>

// practical example of const
const double PI = 3.14;

int main(int argc, char const *argv[])
{
    const int x = 10;
    // x = x + 1; // error: assignment of read-only variable 'x'
    printf("%d\n",x);

/**
 * Although const variables are intended to be read-only, their values
 * can technically be modified using pointers 🤔. However, this is not
 * recommended, as it defeats the purpose of declaring a variable as
 * const. 
 */

    int r;
    printf("Enter value of r:\n");
    scanf("%d",&r);
    printf("Area is: %f\n",PI * r * r);

/**
 * In c, we can also create constants like PI using macros with #define
 * directive rather than using const. While macros are a quick way to
 * define constants, they are not recommended because: 
 *      - Macros simply perform a text substitution without considering
 *        the data types
 *      - Once defined, macros are available throughout the file, 
 *        potentially causing conflicts. 
 */

    return 0;
}
