#include <stdio.h>

/**Struct Modifiers
 * In a perfect world, structs look the same across all systems, however this aint
 * the case in the real world. When optimizing for spacing and ALIGNMENT, the system
 * may add PADDING in the memory blocks to keep them aligned. There are some modifiers
 * that we can use to make this more predictable
 * 
 * If i wanted to serialize for example this data and work on it between two diff
 * systems that might have different architectures, there's a chance that the structures
 * may change between these systems. by adding special modifiers to the strutures,
 * I can ensure that the structure doesn't get modified in this way. As it is right
 * now on one system your element might a certain offset and it'll be different on 
 * another system.
 * 
 * For example
 */

struct mystruct {
    int i;
    char c;
};

// this struct should only have 5 bytes, but there is a pretty good chance that it 
// has 8, or even 16 due to alignment issues. The arch adding padding in there to 
// make it align up with the other memory blocks. So how do we fix this?
// we can add the packed attribute
struct __attribute__((__packed__)) mystruct2 {
    int i;
    char c;
};

// this creates the same struct but tells the arch not to add any padding. "Keep
// my struct packed" 