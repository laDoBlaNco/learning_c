/** Array Casting
 * 
 * Let's look at at a special kinda psychopathy (nice word) that's
 * possible in C. Assume I have this array of 3 structs now where
 * each struct holds 3 ints
 * 
 * Since arrays are basically just pointers (in most cases; I'll 
 * see more about that later), and i know that structs are contiguous
 * in memory, then I can cast the array of structs to an array
 * of integers
 * 
 * Then iterate over the known number of ints in the array structs
 */
#include <stdio.h>

typedef struct Coordinate
{
    int x;
    int y;
    int z;
} coord_t;

typedef struct Graphics
{
    int fps;
    int height;
    int width;
} graphics_t;

void dump_graphics(graphics_t *);


int main(int argc, char const *argv[])
{
    
    coord_t points[3] = {
        {5,4,1},
        {7,3,2},
        {9,6,8},
    };

    int *points_start = (int *)points;

    for (int i = 0; i < 9; i++) {
        printf("points_start[%d] = %d\n",i,points_start[i]);
    }
    printf("\n\n");

    //====================================================
    /*
        Looking at the dupmp graphics function which works similarly
        to what I'm doing above. But after I run it all hell breaks
        loose. After all the specified values are printed it then 
        ventures out of the bounds of my array! I'm off the reservation
        In the C weeds. In UNDEFINED territory. This is something
        I shouldn't want to do. Its of the things that makes C so
        powerful but also so dangerous. Other languages stop me from
        going out of bounds, but C will let me fly off the edge of
        world and dive into almost anywhere I want to go. 

        Let me fix the loop to only print the values that are actually
        in the array of structs by putting a limit on the number of
        times the loop runs. 

        Answer = The struct is actually 10 elements of 3 ints
        so the total is 30. So the loop should be < 30.
    
    */
    graphics_t graphics_array[10] = {
        {60, 1080, 1920},
        {30, 720, 1280},
        {144, 1440, 2560},
        {75, 900, 1600},
        {120, 1080, 1920},
        {60, 2160, 3840},
        {240, 1080, 1920},
        {60, 768, 1366},
        {165, 1440, 2560},
        {90, 1200, 1920}
    };
    dump_graphics(graphics_array);




    return 0;
}

void dump_graphics(graphics_t gsettings[10]){
    int *ptr = (int *)gsettings;
    // for (int i = 0; i < 30; i++) {
    // going through it again I'm changing it so I can see whats
    // really happening under the hood with the management of 
    // memory. Its 10 items with 3 fields each
    for (int i = 0; i < (10 * 3); i++) {
        printf("settings[%d] = %d\n",i,ptr[i]);
    }
}