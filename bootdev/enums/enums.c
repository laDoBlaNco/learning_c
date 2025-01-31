/**Enums:
 * 
 * Unlike Go (a language from the 70s) C, has explicit support for
 * enums (enumerations) with the enum keyword. 
 */
#include <stdio.h>

// We define a new enum very much like a struct with typedef
typedef enum DaysOfWeek {
    MONDAY,
    TACO_TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    FUNDAY,
} days_of_week_t; // note we still end it with _t as a type
// so it is an enum_type just like we did struct_types

/**
 * The typedef and its alias days_of_week_t are optional, but like
 * structs, they make the enum easier to use
 * 
 * In the above example, days_of_week_t is a new type that can only
 * have one of the values defined in the enum:
 * 
 *      🔸 MONDAY is 0
 *      🔸 TACO_TUESDAY is 1
 *      🔸 WEDNESDAY is 2
 *      🔸 THURSDAY is 3
 *      🔸 FRIDAY is 4
 *      🔸 SATURDAY is 5
 *      🔸 FUNDAY is 6
 * 
 * I can use them like this
 */

typedef struct Event {
    char *title;
    days_of_week_t day;
} event_t;

// or without the alias
typedef struct Event2 {
    char *title;
    enum DaysOfWeek day; // just like using struct over and over again
} event2_t;

// an enum is NOT a collection type like a struct or an array. It's 
// just a list of integers constrained to a new type. This is why its
// strictly ENUMERATIONS. And each integer is given an explicit name.

// Assignment:
// Create a Color enum (and color_t with typedef) with RED,GREEN,BLUE
// in that order
typedef enum Color {
    RED,
    GREEN,
    BLUE,
} color_t;
