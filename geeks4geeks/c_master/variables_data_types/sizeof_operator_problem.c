#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*The sizeof operator -- 
    
    Here I'll practice the sizeof operator in C. This operator is a 
    unary type -- it takes only one operand as input and outputs the
    size in bytes of the operand. I'll be given four different variables
    of different data types
        a(int)
        b(float)
        c(double)
        d(long long)
    
    The task is to print size in bytes of these four data types    */

    int a;
    scanf("%d",&a);
    float b;
    scanf("%f",&b);
    double c;
    scanf("%lf", &c);
    long d;
    scanf("%ld",&d);

    // print the size of a, b, c, d using sizeof() operator
    printf("%zu %zu %zu %zu\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));

    return 0;
}
