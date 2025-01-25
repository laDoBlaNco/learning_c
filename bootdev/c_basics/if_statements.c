/**If Statements
 * 
 * If statements are the most basic form of control flow in C
 * very similar ot other languages. Normat syntax:
 * 
 * if (x > 3) {
 *  printf("x is greater than 3\n");
 * }
 * 
 * if..else if... else
 * 
 * if (x > 3){
 *      printf("x is greater than 3\n");
 * } else if(x == 3){
 *      printf("x is 3\n");
 * } else{
 *      printf("x is less than 3\n");
 * }
 * 
 * Just like other languages when its just one statement you can leave
 * out the brackets. Some folks don't like this, I don't mind too much
 * 
 */

#include <stdio.h>

char *get_temperature_status(int temp);

int main(int argc, char const *argv[])
{
    int temp = 66;
    printf("The temp: %d is %s.\n",temp,get_temperature_status(temp));
    return 0;
}

char *get_temperature_status(int temp){ // returning a string (char array) (array of pointers) 😅
    if (temp < 70) {
        return "too cold";
    } else if (temp > 90){
        return "too hot";
    } else {
        return "just right";
    }

}
