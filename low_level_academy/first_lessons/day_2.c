// Today let's look at variables. they are like containers that hold
// data in a program. They allow you to store and manipulate information
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declare variables
    char name[50]; // this variable will store the name entered by user

    // let's get user input
    printf("Enter your name: ");
    scanf("%s",name);  // scan stdin and put in 'name' array

    // display personalized greeting
    printf("Hello, %s! Welcome to Day Two of the C Programming Course.\n", name);
    return 0;
}
