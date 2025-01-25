/**Strings 
 * Most programming languages these days (even compiled ones) have a 
 * built-in string type of some sort. C ... doesn't. Instead C strings are 
 * just arrays (like lists) of chars. We'll talk mroe about the specifics
 * when we go through arrays and pointers alter, but for now know that this
 * is how we get strings in C
 * 
 * char *msg_from_dax = "You still have 0 users";
 * 
 * Very (VERY) loosely speaking, char * means string. It actually means
 * pointer to a character as I learned in pointer arithmetic. From what I 
 * deduce if a string is just an array of character elements, then the variable
 * identfier for a string in memory is just a pointer to the first char and
 * then with pointer arithmetic you get to the rest of the chars
 * 
 * msg_from_dax points to "Y"
 * msg_from_dax + 1 points to "o"
 * msg_from_dax + 2 points to "u"
 * ...
 * 
 * Also note that the "" is required in C. '' are used to make chars not char *
 * 
 * Fix the bug so we can compile
 */
#include <stdio.h>

int main() {
  char *will_never_hear_again =
      "Hey TJ, when is the memory course in C gonna be done?";

  // don't touch below this line
  printf("\n");
  printf("%s\n", will_never_hear_again);
  printf("\n");
  return 0;
}

