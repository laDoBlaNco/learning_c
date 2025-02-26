/**
 * So what does a complete C program look like?
 *
 * Most start with comments describing the purpose of the code and might include some licensing info:
 *
 * Program to calculate the number of cards in the shoe
 * This code is released under the Vegas Public License
 * (c) 2014, The College Blackjack Team
 */

// next will typically be some #include statements
// C is a very very small language and it can do almost nothing without including external libs
#include <stdio.h>

// Then we have the functions. All C code runs inside functions. The most
// important of these is with 'main' function which is the starting point
int main(int argc, char const *argv[])
{
    int decks;
    puts("Enter a number of decks");
    scanf("%i", &decks);
    if (decks < 1)
    {
        puts("That is not a valid number of decks");
        return 1;
    }
    printf("There are %i cards\n", (decks * 52));
    return 0;
}

/**
 * A little more detail about main: 
 * The name is important. If there's no function called main the program won't be able 
 * to start. 
 * 
 * The return type is int, when the computer runs the program it'll need to have some way
 * of deciding if everything went well. It does this by checking the return value. Returning 0
 * means all good and anything else means there was an issue. 
 * 
 * NOTE: if you want to check the exit status of a program type: 
 *  ▫️ echo %ErrorLevel% for windows
 *  ▫️ echo $? for linux or Mac
 * 
 * 
 */
