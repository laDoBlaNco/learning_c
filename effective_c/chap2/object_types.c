#include <stdio.h>
#include <stdbool.h>

/**Object Types:
 * 
 * so in this section we'll talk about the object types in C. Specifically, covering
 * the bool, char, and numerical types which include int and float. 
 * 
 * Let's start with bools:
 * Objects  declared as _Bool or bool can only store 0 and 1. This was introduced
 * in c99 and started with '_' so it would be backward compatible with other implementations
 * at the time. Strange that something as basic as a boolean wasn't in the original
 * language 🤔 In c any identifier starting with a _ and either upper or lowercase
 * are always reserved words. If people didn't avoid using those in their implementations
 * that's their fault.  
 * 
 * I have to include #include <stdbool.h> in order to use the spellng 'bool' and 
 * use it with 'true' or 'false' which just expandds to 1 or 0
 * Both spellings will work, but its better to use 'bool', as this is the longterm
 * direction of C
 * 
 */

_Bool flat1 = 0; // so this works without any include file

bool flag2 = false; // for this I must have the stdbool.h included. 

/**Character Types:
 * 
 * There are 3 main char types in C: 
 *  - char
 *  - signed char
 *  - unsigned char
 * 
 * echo compiler will implement char to have the same alignment, size, range, rep
 * and behavior as either signed char or unsigned char. Regardless of the choice made,
 * char is a separate type from the other two andis incompatible with both. 🤔 ???
 * 
 * The char type is typically use to rep character data in C, in particular, objects of
 * type char must be able to rep the minimum set of chars required in the execution 
 * env or the basic execution character set. including both upper and lowercase letters
 * the 10 decimal digits, the space char, and various punctuation and control chars. 
 * The char type is inappropriate for integer data; it is saver to use signed char 
 * to represent small signed integer values, and unsigned char to represent small 
 * unsigned values instead of the chars 0 - 9
 * 
 * The basic execution char set suits the needs of many conventional data processing
 * apps, but its lack of non-english letters is an obstacle to acceptance by 
 * international users. To address this the standards committee specified a new, wide
 * type to allow large char sets. I can rep the chars of large char sets as wide
 * characters by using the wchar_t type, generally taking more space than a basic
 * char. typically 16 or 32 bits are used to rep a wide char
 * 
 */

/**Numerical Types
 * 
 * There are several numerical types that can be used to rep integers, enumerators, 
 * and floats. in Chap 3 I'll some of these in more detail, but here is a summary
 * 
 * Integer type:
 * Signed integer types can be used to rep negative numbers, positive numbers and zero.
 * the signed int type include signed char, short int, int, long int, and long long int.
 * 
 * Except for int itself, the keyword int may be omitted in the declarations for these
 * types, so can can use for example 'long long' instead of 'long long int'
 * 
 * For each signed int type, there is a corresponding unsigned int that uses the same
 * amount of storage: unsigned char, unsigned short int, unsigned int, unsign long int,
 * and unsigned long long int. these types can only be used ro rep positive nubmers
 * and zero
 * 
 * The signed and unsigned integer types are used to rep integers of various sizes. Each
 * platform (current and historical) determine the size for each of these types, given
 * some constraints. Each type has a minimum representable range. The types are ordered
 * by width, guaranteeing that wider types are at least as large a narrower types, this
 * way an object of type long long int can rep all values that type long int can. I can
 * infer the actual sizes of the various ints from the max and min representable values
 * specified in <limits.h>
 * 
 * The int type usuall has the natural size suggested by the arch fo the exec env, so
 * teh size would be 16 bits  on a 16-bit arch, 32 on a 32-bit arch, etc. I can also 
 * specify actual width ints by using typedefs from the <stdint.h> or <inttypes.h> 
 * files, like uint32_t. chapter 3 covers ints types in excruciating detail
 * 
 */

/**Enum Types:
 * 
 * An enum is something that I learned more about with Python and allows me to define
 * a type that assignes names (enumerators) to interger values in cases with an 
 * enumerable set of constant values. the following examples are enumerations
 */
enum day {sun,mon,tue,wed,thu,fri,sat}; // if you don't specify the number it'll start
// as 0 and label each subsequent enumerator adding 1.
enum cardinal_points {north=0,east=90,south=180,west=270}; // Or we can specify the 
// constant number with '='. Using '=' can present constants with dup values.
enum months {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec}; // finally I can give
// the starting number and C will add in the subsequent enumerators adding 2.


/**Floating-Point Types:
 * 
 * C supports 3 floating point types: float, double, and long double. Floating point
 * math is similar to and often used as a model for the arithmetic of real numbers.
 * C supports a variety of floating-point representations including, IEEE Standard for
 * Floating-Point Arithmetic (IEEE 754-2008). The choice of floating-point representation
 * is implementation dependent. 
 * 
 */

/**Void Types:
 * 
 * The void type is a rather strange fellow. The kw void (by itself) means
 * 'cannot hold any value'. For example, I can use it to indicate that a function
 * doesn't return a value, or as the sole parameter of a function to indicate that
 * the function takes no args. On the other hand, the DERIVED TYPE void * means that
 * the pointer can reference ANY object. Well look at derived types later in this
 * chap.
 * 
 */