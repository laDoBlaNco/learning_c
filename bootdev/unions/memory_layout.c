/**Memory Layout
 * 
 * So Unions store their value in the same memory location, no
 * matter which field or type is actively being used. This sounds
 * dangerous to me, but let's see. That means that accessing any
 * field apart from the one you set is generally a bad idea. So this
 * would open us up to seg faults, undefined behaviors, and bugs
 * 
 * Assignment:
 * Understand the following example:
 */
#include <stdio.h>
#include "limits.h"

typedef union {
    int value;
    unsigned int err;
} val_or_err_t;

int main(){
    val_or_err_t lanes_score = {
        .value = -420
    };
    printf("value (set): %d\n",lanes_score.value);
    printf("err (unset): %u\n",lanes_score.err);
/**
 * Note above that .value is set to -420, then the data in each
 * field (including the one we didn't set) is printed. The .value
 * works as I'd expect, but the .err field prints 4294966876. This
 * is because its trying to interpret -420 as an unsigned integer
 * resulting in a very large number. 
 * 
 * Let's now add an edit 
 */
    val_or_err_t teejs_score = {
        .err = UINT_MAX
    };
    printf("value (unset): %d\n", teejs_score.value);
    printf("err (set): %u\n", teejs_score.err);

    /**
     * Now note how setting the .err as an unsigned int, I now get
     * the .err field to print as expected, but the .value field is
     * now printing -1. Again, C is trying to now interpret the
     * bytes of our unsigned max as a signed int, which is -1
     */
}