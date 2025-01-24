// Now we go into control flow allowing our programms to start to
// make decisions. 
#include <stdio.h>

int main()
{
    // Declare a variable
    int age;

    // Get user input
    printf("Enter your age: ");
    scanf("%d",&age); // note that here we had to put & but for the
    // array we didn't??? 🤔

    // make a decision based on the user's age
    if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } else {
        printf("Sorry, you are not eligible to vote yet.\n");
    }

}