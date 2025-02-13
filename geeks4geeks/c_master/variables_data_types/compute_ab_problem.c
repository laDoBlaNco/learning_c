/**Compute a/b
 * 
 * Given two integers a and b. Finda the value of a/b, where b is
 * not equal to zero. After computation, print the value. The
 * answer should be in double format with precise values.
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d", &a, &b);

    printf("%f\n",(double)a/b);
    return 0;
}
