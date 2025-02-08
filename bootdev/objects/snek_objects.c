/**Snek_Objects: 
 * 
 * Objects in C?!? No. Way, How???
 * 
 * For this project sneklang is built in C and everything in sneklang is an object
 * For clarity though I'm not talking about classes or OOP, but a higher-level
 * data structure that holds some metadata about itself. For example it'll store: 
 *      ▫️ What type of data it holds (int, float, string, etc)
 *      ▫️ The size of the data it holds
 *      ▫️ The data itself
 *      ▫️ How many references to itself exist (at least later, when I build
 *        the gc)
 * 
 * That last point is critical for this project because sneklang is garbage collected
 * so I need to know how many references to an object exist so I can free  it when
 * it's no longer needed. 
 */
#include <stdio.h>

// an enum with a single value INTEGER
typedef enum {
    INTEGER,
} snek_object_kind_t;

// a union called snek_object_data_t with a single member, an integer named
// v_int
typedef union {
    int v_int;
} snek_object_data_t;

// a struct declaration called snek_object_t with 2 members
//      ▫️ a member of type snek_object_kind_t named kind
//      ▫️ a member of type snek_object_data_t named data
typedef struct {
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

int main(int argc, char const *argv[])
{
    
    return 0;
}



