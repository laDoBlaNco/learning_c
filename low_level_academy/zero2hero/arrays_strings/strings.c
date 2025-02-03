#include <stdio.h>

int main(int argc, char const *argv[])
{
	/**
	 * We've gone through arrays, but Strings can sometimes trip us up. What 
	 * really is a string. Well if an array is just a contiguous block of memory
	 * set to a specific size with certain elements assigned of the same type
	 * a string is very similar if not the same thing. 
	 * 
	 * A string is a structure in C that actually gets people in trouble a LOT
	 * Tons of security vulnerabilities in modern software are caused by buffer
	 * overflows, and most of those buffer overflows have to do with strings. 
	 * So what is a string you ask?
	 * 
	 * A string is just an array of chars. Yup, seriously, Its that easy. An array
	 * is just a block of memory that contains a set of variables that are the same
	 * type, as mentioned above, So if those variables are chars? well now we have
	 * a string.
	 */

	char my_str[] = {'h','e','l','l','o'};
	printf("Hello, I am a string\n");
	printf("%s\n",my_str);

	/**
	 * Strings are special:
	 * A string in C has a very special characteristic that makes it amazing,
	 * but also dangerous. All strings in C are ended with a null byte. If they
	 * don't dend in a null byte, the operation you'll be performing never
	 * complete.
	 * 
	 * Why does this matter?
	 * If you run operations like strcpy, which copies data from the src  buffer
	 * to the dest buffer. It will ONLY STOP COPYING OR PRINTING IF IT ENCOUNTERS
	 * THAT ZERO BYTE. So, the code above actually has a pretty major security 
	 * vulnerability. You have to make sure your strings end with a zero, otherwise
	 * things will go sideways. 
	 * 
	 * NOTE: I think thats what's happening in the result of running this code. I'm 
	 * seeing something weirdness after that hello above as if some junk bytes are 
	 * being printed. 
	 */

	// this is how it should be
	char my_str2[] = {'h','e','l','l','o',0};
	printf("%s\n",my_str2);

	// something else is that to create a string in a var we do, maybe since
	// we are creating a string, C puts in the null byte at the end.
	// this was confirmed, since there's a "" the compiler knows to add the null byte
	char *my_other_str = "hello";
	// not sure why this is???
	printf("%s\n",my_other_str);

	char my_str3[] = {'h','e','l','l','o',0};
	printf("%s\n",my_str3);


	return 0;
}