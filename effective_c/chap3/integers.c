/**Arithmetic Types:
 * 
 * In this chapter I'll learn about the two kinds of arithmetic types. Integers
 * and floating-point types. Most operators in C operate on arithmetic types. 
 * Since C is a system-level language, performing arithmetic operations correctly
 * can be difficult - resulting in frequent defects. This is partically 
 * due to arithmetic operations in digital systems with limited range and
 * precision do not always produce the same result as they would in ordinary
 * mathematics. So being able to perform basic arithmetic correctly in
 * C is an essential foundation to becoming a professional C programmer.
 * 
 * So Ill e diving deep into how arithmetic works in the C language so
 * that we have a firm grasp of the fundamental concepts.  Let's 
 * also look at how to convert one type to another, which is necessary
 * for performing operations on mixed types.
 * 
 * Integers:
 * As learned in chap2, each int type represents a finite range of
 * ints. Signed int types rep values that can be negative, zero, or
 * positive; unsigned integers rep values that can be only zero or
 * positive. The range that each tyep of int can rep depends on
 * the implementation. 
 * 
 * The value of an int object is the ordinary
 * mathematical value stored in the object. The representation of a
 * value for an int is the particular encoding of the value of the bits 
 * of the object's allocated storage. Let's look at the representation 
 * in more detail later. 
 * 
 * Padding and Precision:
 * All int types except char,signed char, and unsigned char may contain
 * unused bits called padding, that allow implementations to accomodate
 * hardware quirks (such as skipping over a sign bit in the middle of a 
 * multuiple-word instruction) or to optimally align with a target archictecture)
 * 
 * The number of bits used to rep a value of a given type, excluding padding
 * but including the sign, is called the width and is often denoted by N.
 * The precision is the number of bits used to represent values, excluding
 * sign and padding bits.
 * 
 * The <limits.h> file provides the min and max representable value for the
 * various integer types. A representable value is one that can be represented
 * in the number of bits avaiable to an object of a particular type. Values
 * that can't be represented will be diagnosed by the compiler or converted to
 * a representable but different (incorrect) value. Compiler writers provide
 * the correct min and max and width values for their implementations. To
 * write portable code I should use these constants rather than integer literals
 * such as +2147483647 to rep specific limits and may change when porting
 * to a different implementation. 
 * 
 * The C standard imposes only 3 constraints on integer sizes. First, storage
 * for every data type occupies an integral number of adjacent unsigned char
 * objects 9which may include padding) Second each int type has to support
 * the minimum ranges, allowing me to depend on a portable range of values
 * across any implementations. Third, smaller types can't be wider than larger
 * types. So for exaample, USHRT_MAX can't be greater than UINT_MAX, but they
 * can be the same width.
 * 
 * Declaring Ints
 * Unless explicitly declared as unsigned, int types are assumed to be signed
 * (except for char, which the implementation can define as either a signed
 * or unsigned int type) The following are all valid declarations of unsigned
 * integers:
 *      - unsigned int ui; // unsigned is required
 *      - unsigned u; // int can be omitted
 *      - unsigned long long ull2; // int can be omitted
 *      - unsigned char uc; // unsigned is required
 * When declaring signed integer types I can omit the signed keyword except
 * for signed char, which requires the keyword to disinguish signed char from 
 * plain char. Unless it is the only keyword present, int can also be omitted
 * So instead of signed long long int, I can use long long and save some typing
 *      - int i // signed can be omitted
 *      - long long int sll; signed can be omitted
 *      - long long sll2; signed and int can be omitted
 *      - signed char sc; signed is required
 * 
 * Unsigned Integers:
 * 
 */