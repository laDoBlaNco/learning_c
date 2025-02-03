/**Stack Overflow
 * 
 * So the stack is great and all, but one of the downsides is that
 * it has a limited size. If I keep pushing frames onto the stack
 * without popping them off, I'll potentially run out of memory
 * and get a STACK OVERFLOW (yes, that's what the famous site is
 * named after)
 * 
 * That's one of the reasons recursion without tail-call optimization
 * can be dangerou. Each recursive call pushes a new frame onto the
 * stack, and if I have too many recursive calls, I'll run out of 
 * stack space. 
 * 
 * Assignment: 
 *      1. Run the code in its current state. I get a stack overflow
 *         which causes a seg faultpoint
 *      2. Fix the pool_size so that it allocates exactly 10 kibs
 */

#include <stdio.h>

int main() {
    const int pool_size = 1024 * 10;
    char snek_pool[pool_size];
    snek_pool[0] = 's';
    snek_pool[1] = 'n';
    snek_pool[2] = 'e';
    snek_pool[3] = 'k';
    snek_pool[4] = '\0';

    printf("Size of pool: %d\n", pool_size);
    printf("Initial string: %s\n", snek_pool);

}

/** What's a Kibibyte 🤯🤯🤯🤯🤯 
 * I had no idea about this this. Aha moment here: 
 * A kibibyte (KiB) is a unit of digital information measurement 
 * equal to 1,024 bytes, used primarily in computer science contexts 
 * where binary prefixes are preferred, meaning it represents a 
 * power of 2 rather than a power of 10 like the traditional "
 * kilobyte" which can sometimes be interpreted as 1,000 bytes; 
 * essentially, a kibibyte is a more precise way to denote 1024 
 * bytes in a binary system
 * 
 * 1 KB equals 1,000 bytes; 1 kibibyte (KiB) equals 1,024 bytes.
*/