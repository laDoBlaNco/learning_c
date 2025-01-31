/**Non-Default Values
 * 
 * Sometimes I won't just want to enumerate  some names (where the
 * underlying integer constant value don't really matter)... I may
 * want to set those enumerations to specific meaningful values.
 * 
 * For example, maybe defining a program's exit status
 */
#include <stdio.h>

typedef enum {
    EXIT_SUCCESS = 0,
    EXIT_FAILURE = 1,
    EXIT_COMMAND_NOT_FOUND = 127,
} ExitStatus;

// Alternatively I can also define the first value and let the 
// compiler fill in the rest (incrementing by 1) (JUST LIKE GO)
typedef enum {
    LANE_WPM = 200,
    PRIME_WPM, // will be 201
    TEEJ_WPM, // will be 202
} WordsPerMinute;

// Assignment: Update the Color enum from the last file to 
// the following values
// 🔸 RED = 55
// 🔸 GREEN = 176
// 🔸 BLUE = 38

typedef enum Color {
    RED = 55,
    GREEN = 176,
    BLUE = 38,
} color_t;

int main(){
    printf("Enum ExitStatus:\n\t"
           "EXIT_SUCCESS is %d\n\t"
           "EXIT_FAILURE is %d\n\t"
           "EXIT_COMMAND_NOT_FOUND is %d\n\n",
           EXIT_SUCCESS,EXIT_FAILURE,EXIT_COMMAND_NOT_FOUND);

    printf(
        "Enum WordPerMinute:\n\t"
        "LANE_WPM is %d\n\t"
        "PRIME_WPM is %d\n\t"
        "TEEJ_WPM is %d\n\n",
        LANE_WPM,PRIME_WPM,TEEJ_WPM
    );

    printf(
        "Enum Color:\n\t"
        "RED is %d\n\t"
        "GREEN is %d\n\t"
        "BLUE is %d\n\n",
        RED,GREEN,BLUE
    );
} 
