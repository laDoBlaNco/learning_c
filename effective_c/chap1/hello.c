#include <stdio.h>
#include <stdlib.h>
// so this idea including files in PHP comes directly from this in C
// same thing with a different syntax.

int main(void)
{
	// though this is the first time i see puts() it must come from the
	// stdio.h. It simply adds a string to stdout with a "\n" implied.
	
	// we can add a check on the return value of our function call to make this
	// professional grade level hello world in C
	if (puts("Hello, world!") == EOF) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

// Th emain function that's called defines the main entry point of our program. C 
// defines 2 possible execution envs: freestanding and hosted. A freestanding env may
// not provide an operating system and is typically used in embedded programming. These
// implementations provide  a minimal set of library functions, and the name and type
// of function called at program startup are implementation defined. We will be working
// with a hosted env in this book.

// The revised version of our program above checks whether the puts call returns the
// value EOF, indicating a write error. If the function returns EOF, the program returns
// the value of EXIT_FAILURE macro. Otherwise it returns EXIT_SUCCESS which will be 0

// for formated printing we use printf()



