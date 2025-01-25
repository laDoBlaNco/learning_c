/**Basic Types:
 * 
 * I've already seen int in the other examples as the return value for
 * our main function. some other basic types are:
 *  - int - integer
 *  - float - a floating point number
 *  - char - a character
 *  - char * - an array of characters (more on this later .. but considering
 *    all things an array of chars just sounds like a ... string, right?)
 * 
 */
#include <stdio.h>

// add the types so this compiles
int main() {
  int max_recursive_calls = 100;
  char io_mode = 'w';
  float throttle_speed = 0.2;

  // don't touch below this line
  printf("Max recursive calls: %d\n", max_recursive_calls);
  printf("IO mode: %c\n", io_mode);
  printf("Throttle speed: %f\n", throttle_speed);
  return 0;
}