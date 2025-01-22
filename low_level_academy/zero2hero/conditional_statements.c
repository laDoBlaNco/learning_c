#include <stdio.h>

/**
 * Up until this point, we've written code t hat contains variables. But our
 * code doesn't actually do anything. When we write code for computers, we're 
 * effectively asking the computer to perform logic for us. So far, our code
 * hasn't had any conditional logic. This changes, now.
 * 
 * Conditional Statements
 * In C, if we want our code to take a certain path based on the state of the 
 * program, we have to create what is called a conditional statement. One type
 * of conditional statement is what is referred to as an "if statement"
 * 
 * An if statement says, "only do this thing if the following condition is true",
 * for example: * 
 */

int main(int argc, char const *argv[])
{
	int x = 24;

	// .. get value from the user...
	if (x == 42){
		printf("You said 42!\n");
		// the above only prints if x is 42
	} else if (x == 24){
		printf("You said 24!\n");
	} else {
		printf("You said something else!\n");
	}

	printf("\n");

	int temp;
	printf("What temperature is it? ");
	scanf("%d",&temp);

	if (temp >= 70) {
		printf("dang, bruther, it's hot\n");
	} else if (temp >= 30 && temp < 70) {
		printf("dang, bruther, it's mild\n");
	} else {
		printf("dang bruther, its cold\n");
	}

	return 0;
}

/**
 * Computers run on binary, which is a 1 or 0, effectively it can only take
 * action if things are true or not true. An if statement does jus that: It
 * runs some statement and if the result is true, it takes an action.
 * 
 * Else statement
 * We can add some more code to the above to take an additional action. Like
 * else. The else clause says  "do this other thing if the condition is false"
 * 
 * if-else
 * There is one more conditional logic that we can use with if statements. We 
 * can chain multiple if-statements together that are mutual in their logic, by
 * using an if-else tree. The if-else tree will check each logical condition in 
 * order, and execute the first one that is true. After that, it will stop checking
 * the tree, for example:
 */