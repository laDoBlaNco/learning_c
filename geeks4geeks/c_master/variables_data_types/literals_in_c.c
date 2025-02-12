#include <stdio.h>


int main(int argc, char const *argv[])
{
    /**
     * Literals in C
     * 
     * In C literals are the constant values that are assigned to the
     * variables. They represent fixed values whose meaning does not
     * change during program execution. For example, 'float x = 3.14' 
     * is an expression and the value 3.14 is referred to as an integer
     * literal. 
     * 
     * There are 4 types of literals in C corresponding to the different
     * data types in C: 
     * 
     *  1. Integer Literals
     *     Integer literals are used to represent and store the integer
     *     values only. it an have prefix and suffix that indicates
     *     different properties of the literal. 
     * 
     *      Integer Literals with Prefix
     *      The prefix of the integer literal indicates the base on which
     *      it is to be read: 
     *      🔹 No prefix: Decimal value (e.g. 20)
     *      🔹 0x or 0X: Hexidecimal value (e.g. 0x1A)
     *      🔹 0: Octal value (e.g. 016)
     *      🔹 0b or 0B: Binary value (GCC extension, not part of the 
     *         standard, e.g. 0b11)
     */
    int a = 20; 
    int b = 0x1a;
    int c = 016;
    int d = 0b11;

    printf("%d %d %d %d\n",a,b,c,d);

    /**
     * Integer Literals with Suffix
     * The suffixes of the integer literal indicate the type in which 
     * it is to be read
     * 🔹 u or U: Unsigned (e.g. 124U)
     * 🔹 l or L: Long (e.g. 124L)
     * 🔹 ll or LL: Long Long (e.g. 124LL)
     */
    int e = 124;
    unsigned int f = 124u;
    long int g = 124L;
    long long h = 124LL;

    /**
     * 2. floating-point literals: 
     * Floating-point literals are used to represent real numbers. The
     * real number has an integer part and a fractional part. In floating
     * point literals, allowed prefix is '0x' or allowed suffix are 'f for
     * float and l for long double'
     */
    float i = 10.5f;
    double j = 10.515;
    long double k = 10.515l;
    float l = 2.1e4f; // 2.1x1^4 = 21000
    double m = 200.1e-80; 
    double n = 0x1a.1p2;
    printf("%g %g %Lg %g %g %g\n",i,j,k,l,m,n);
    // by default in C, if you do not write any suffix with floating 
    // it will be treated as a double

    /**
     * 3 & 4 Character and String Literals
     * Character literals refer to the literal that is used to store
     * a single character within a single quote
     * 
     * String literals are similar to that character literals, except
     * that they can store multiple characters and use double quotes
     * to store the same. It can also accomodate the special characters.
     * String literals are immutable and stored in a read-only memory area. 
     */
    char ch = 'g';
    const char *s = "gfg";

    printf("%c %s\n",ch,s);


    return 0;
}
