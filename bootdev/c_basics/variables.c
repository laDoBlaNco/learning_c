/**Variables:
 * As we talked about, variables cannot change types (shouldn't)
 * 
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 5;
    // float x = 3.14; // should give an error

    x = 15; // this is ok as the value can change but not the type
    // x = "15"; // this just gets us an warning as apparently it'll convert but
    // warning that we did it without a (cast) and it won't print or result
    // correctly as its pointing to junk memory looks like
    printf("%d\n",x);

    // fix this bug by removing second type declaration
    int sneklang_int_size = 64;
    sneklang_int_size = 32;
    printf("Sneklang int size: %d bits\n", sneklang_int_size);

    return 0;
}
