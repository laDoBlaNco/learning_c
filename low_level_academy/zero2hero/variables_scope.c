#include <stdio.h>

// here we are talking about scopes. We can update a var if it was
// initialized in scope. So we can update our var in main, but not the one
// in our random function

// there is also Global scope
int g_num_persons = 0;  // this can be reached in any of our functions, not great code

void some_other_function()
{
	int personID = 1;
}

int main()
{
	// type name = initial value;
	int personID = 0;

	// we can update this because its in local scope
	personID += 1;  // this works.

	{
		// we can also create sub-scopes with the curly brackets
		// and again, these are not accessible and different from the 
		// vars out of this scope
		int personID = 0;

		personID += 1;
	}
}