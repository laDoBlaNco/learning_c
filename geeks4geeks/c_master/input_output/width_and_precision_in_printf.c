/*
Width and Precision in printf()

When formatting output using the printf() function, width and precision are two important
fields that allow us to control how the output is displayed on the screen

    printf("%width.precision",args...)

Width Field
The width field specifies the MINIMUM number of chars to be printed. NOTE that it doesn't control
the amount read or printed, so its not a deterrant to buffer overflows as I thought before. 
If the output is smaller than the specified width, spaces or padding characters are added. The
behavior of width specifier depends on the type of data it is working on. 
    1. Default Behavior
    Without specifiying width, the output is printed as it is. 

    2. Width with integer
    It specifies the minimum number of chars to be printed: 
        ▫️ if the number has fewer digits than the specified width, spaces (or zeros if using 0 flag)
          are added to the left by default. 
        ▫️ Negative sign (-) is counted as a character width as well. 

    3. Width with Strings
    It specifies the minimum number of characters for the string
        ▫️ If the string length is less than the width, spaces are added to the left by default
        ▫️ If the string length exceeds the width, the entire string is printed without truncation

    4. Width with Floating Point Numbers
    Specifies the minimum nubmer of characters for the entire floating-point value (including the
    decimal point and digits after it)
        ▫️ If the value is shorter than the width, spaces (or zeros if using the 0 flag) are added

    5. Dynamic Width
    We can use a * to specify the width dynamically as an additional parameter to printf()


*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    puts("");
    int x = 124;
    printf("%d \n",x);
    printf("%5d \n",x);
    printf("\n");

    char y[] = "gfg";
    printf("%5s \n",y);
    printf("\n");
    
    float z = 1.2;
    printf("%5g \n",z);
    printf("%*s \n",6,y); // the dynamic arg goes first
    printf("\n");

    /*
    Flags with Width
    Flags are provided with width to modify its normal behavior. There are two flags for width 
    specifier: 
        ▫️ - (Left align): Aligns output to the left
        ▫️ 0 (zero padding): Pads with zeros instead of spaces (for numeric only)
        ▫️ + (positive sign): prints positive sign for positive values
    */
   printf("%-5d %-5s %f\n",x,y,z);
   printf("%05d\n",x);
   printf("%+5d\n",x);

   /*
   Precision Field
   Theprecision field is primarily used for floating-point numbers and strings 🤔. It controls the
   number of characters or decimal places to be printed. Like width, it can be dynamic and can be
   used along with precision. 

   The behavior of precision specifier also depends on the type of data it is working on. 

   1. for Strings
   Precision speciies the maximum number of characters to be printed
    ▫️ If the string has more characters than the precision, it is truncated. 
        -- ok this is what I was looking for or thinking before. So with strings width is min and 
           precision is max and can actually be used to deter buffer overflows. 
    ▫️ If the string has fewer characters, no truncation occurs
    */
   char a[] = "geeksforgeeks";
    puts("");
    printf("%.3s\n",a); // after the '.' is precision, so limit 3 chars
    printf("%5.3s\n",a); // before the '.' is width, so width of 5 (pad with spaces) and limit 3
    printf("%*.*s\n",5,3,a); // same as above with %5.3
    printf("%-5.3s\n",a);

    /*
    2. For Floating-point Numbers
    Precision determines the number of digits after the decimal point
        ▫️ If the number of digits exceeds the specified precision, rounding occurs
    %f: prints the number in fixed-point notation.
    */
    double b = 1.345;
    puts("");
    printf("%.2f\n",b);
    printf("%5.2f\n",b);
    printf("%*.*f\n",5,2,b);
    printf("%0*.*f\n",5,2,b);
    printf("%-5.2f\n",b);

    /*
    %e: prints the number in exponential notation with precision specifying the digits after
    the decimal
    */
    double c = 1.345;
    puts("");
    printf("%.2e\n", c);
    printf("%5.2e\n", c);
    printf("%*.*e\n", 5, 2, c);
    printf("%0*.*e\n", 5, 2, c);
    printf("%-5.2e\n", c);

    /*
    %g: Chooses between fixed-point or exponential form based on the value, with precision
    determining the significant digits
    */
    puts("");
    printf("%.2g\n",c);
    printf("%5.2g\n",c);
    printf("%*.*g\n",5,2,c);
    printf("%0*.*g\n",5,2,c);
    printf("%-5.2g\n",c);

    /*3. For Integers
    Precision specifies the minimum number of digits to be printed. It basically has the same
    meaning as width in this case except that it adds 0 in the beginning and does not consider 
    the - sign as chracter*/

    int d = 123;
    puts("");
    printf("%.5d\n",d);
    printf("%.5d\n",-d);
    printf("%5d\n",d);
    printf("%05d\n",-x);

    return 0;
}
