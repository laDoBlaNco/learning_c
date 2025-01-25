/**Printing Variables:
 * 
 * I've already seen what to do with printf(). Its not like pythons
 * f-strings, but though a little more complicated with its formatter
 * (modifiers) its still interpolation at its best. Better than PHP and
 * really the basis for it all I figure.
 * 
 * So instead of this
 * print(f"Hello, {name}. Your're {age} years old.")
 * 
 * In C we ue format specifiers such as:
 *  - %d - digits (ints)
 *  - %c - characters
 *  - %f - floats
 *  - %s - strings (char *)
 *  - %p - pointers (actual memory addresses)
 *  - many more
 * 
 * printf("Hello, %s. You're %d years old.\n",name,age);
 * 
 * Python actually has this version of interpolation as well before 
 * f-strigns came out.
 * 
 * NEWLINE CHARACTER
 * in Py as mentioned print() autmatically adds a newline char \n.
 * In C we do this manually.
 * 
 * 
 * Use format specifiers so the following compiles
 */
#include <stdio.h>

int main() {
  int sneklang_default_max_threads = 8;
  char sneklang_default_perms = 'r';
  float sneklang_default_pi = 3.141592;
  char *sneklang_title = "Sneklang";
  // don't touch above this line

  printf("Default max threads: %d\n",sneklang_default_max_threads);
  printf("Custom perms: %c\n",sneklang_default_perms);
  printf("Constant pi value: %f\n",sneklang_default_pi);
  printf("Sneklang title: %s\n",sneklang_title);
  // and just to prove a point I made earlier of my understanding of 
  // pointer math, memory moves 1 byte since a char is a byte 🤓🤓🤓
  printf("Sneklang title memory address: %p - %c\n",sneklang_title,*sneklang_title);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+27,*sneklang_title+27);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+18,*sneklang_title+18);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+24,*sneklang_title+24);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+25,*sneklang_title+25);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+14,*sneklang_title+14);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+27,*sneklang_title+27);
  printf("Sneklang title memory address: %p - %c\n",sneklang_title+20,*sneklang_title+20);

  // interestingly incrementing this address gust gives me the alphabet which means
  // the chars used are constants from the system, so the pointer is point to where
  // the chars already are on the system. meaning I would need to use pointer math
  // to get to the actual character I'm looking for, which I attempted to do above


  return 0;
}
