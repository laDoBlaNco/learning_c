#include <stdio.h>

#define MAX_PERSONS 1024 // this looks like a constant, reminds me of PHP 
// constants 'define(CONSTANT, value);'

#define DEBUG

int main()
{
	// This doesn't get talked about enough. The C preprocessor:
	// Everything here that starts with the '#'. With this we can add features
	// to our code to help us debug and even have more features. In the compilation
	// process the first step of four that happens is the preprocessing. Here
	// the c compiler goes into our code and grabs all the '# commands' and either
	// puts code into our file from other files (#include) or creates constants (#define)
	// Then we have preprocessor macros such as our #define DEBUG and #ifdef...endif
	
	#ifdef DEBUG
	printf("WE ARE IN DEBUG MODE: %s:%d", __FILE__, __LINE__);
	#endif

	return 0;
}
/**
 * Here are some notes on some of the preprocessor macros
 * 
 * 	- #define: defines a macro -- #define PI 3.14
 *  - #undef: will undefine a previously defined macro -- #undef PI
 *  - #include: includes an external file -- #include <stdio.h>
 *  - #if: Conditional compilation directive -- #if DEBUG
 *  - #ifdef: Checks if a macro is defined -- #ifdef DEBUG
 *  - #ifndef: Checks if a macro is NOT defined -- #ifndef DEBUG
 *  - #elif: Else if condition for #if -- #elif DEBUG == 2
 *  - #else: Else condition for #if -- #else
 *  - #endif: Ends a #if, #ifdef, or #ifndef block. -- #endif
 *  - #error: Generates a compiler error with a specified message -- #error "Error message"
 *  - #pragma: Specifies diverse behavior depending on compiler -- #pragma once
 *  - #line: Specifies the original line number and file name -- #line 20 "myfile.cpp"
 *  - #warning (GCC): Generates a compiler warning with a specified message (GCC)
 *       -- #warning "Warning message"