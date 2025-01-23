#include <stdio.h>

/**
 * So Iv'e already learned how to create a array. An array is a 
 * really big block of memory that contains variables of the same
 * type adjacent to each other. With the creation of arrays, we 
 * introduce a new problem to our world  of learning C. How do we
 * do mass operations on the array without repeating our code over and over
 * again? Enter loops stage left
 * 
 * Loops
 * In C, we can repeat a line of code multiple times using a control-flow
 * structure called a loop. As the name implies, a loop repeats the same 
 * code over and over again until some condition is met. In C there are 
 * 3 types of loops
 * 
 */


int main(int argc, char const *argv[])
{

    /*
    * For Loop:
    * Created with 3 clauses: the initialization clause the check clause, and the
    * iteration clause. The initialization clause is ran once when the loop starts,
    * the check clause checks if the loop should keep going, and the iteration clause
    * runs on every loop completion
    */
    int ids[32];
    for (int i=0;i<32;i++) {
        ids[i] = i*i;
        printf("%d: %d\n",i,ids[i]);
    }
    printf("\n");

    /**
     * While loop
     * is really simple, it just runs the program inside the loop while the condition
     * is true
     */
    int i = 0;
    while (i<32) {
        ids[i] = i*i;
        printf("%d: %d\n",i,ids[i]);
        i++;  // we can't forget to increase here or we get a forever loop
    }
    printf("\n");

    /**
     * Do-While:
     * is the same as the while loop, but the code inside the loop will ALWAYS
     * execute at least once, regardless of the condition
     */


    do {
        ids[i] = i*i;
        printf("%d: %d\n",i,ids[i]);
        i++;
    } while (i < 32);
    printf("\n");



    return 0;
}


