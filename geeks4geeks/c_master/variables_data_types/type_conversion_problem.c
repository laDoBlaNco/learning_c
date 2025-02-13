/**Type Conversion
 * 
 * Given a double value d, typecast it into an integer value and 
 * return it
 */

 #include <stdio.h>

 int type_cast(double d)
 {
    return (int)d;
 }

 int main(int argc, char const *argv[])
 {
    printf("%d\n",type_cast(10.23));
    return 0;
 }
 