#include <stdio.h>

#define MAX_IDS 32

int main()
{
	// an array is just a contiguous block of memory with the same
	// type of value. They must be of the same type. With different types
	// we get a structure (just like Go) :D

	int ids[MAX_IDS] = {0,1,2}; // or we could also 
	// int ids[] = {1,2,3}; // a more literal syntax

	// to access a value in an array we use our index accessing as expected
	printf("%d\n", ids[2]); 

	// what about adding an item
	ids[3] = 0x41;
	printf("%d\n",ids[3]);

	/**
	 * Arrays are really powerfull in programming . using arrays allows you to group
	 * variables that represent the same kind of information together, both spacially
	 * and logically.
	 * 
	 * Array Syntax:
	 * To declare an array, use the following as we did above with the const
	*/

	int my_ids[32]; // this is an array of 32 ints
	my_ids[3] = 2; // sets the 4th element (zero indexing) to 2
	my_ids[0] = 2; // sets the 1st element to 2

	// as above we then use a value with the same indexes
	printf("%d\n",my_ids[4]); // this will print the 5th element which is ??? 
	// a random junk value seems like. This is my first gotcha in C and managing my
	// own memory

	


}