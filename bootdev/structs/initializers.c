/**Initializers
 * 
 * So how do I go about actually making a struct n C? I've seen how
 * to create the type, but the actual struct. Well there are a 
 * few ways to do it and dpeending on the situation I'll have to
 * use the best one.
 * 
 * Let's create a struct type below and then initialize it in 
 * different ways:
 */
#include <stdio.h>

struct City
{
    char *name;
    int lat;
    int lon;
};

struct Coordinate
{
    int x;
    int y;
    int z;
};

// func declaration; Returning a struct of type Coordinate, taks 3 ints
struct Coordinate new_coord(int,int,int);


int main(int argc, char const *argv[])
{
    // Zero Initializer:
    // first we can initialize everything with zero
    struct City c = {0}; // Im assuming a struct name is also just a pointer??? 🤔

    // Positional Initializer:
    // we can also set values as we would args in a function, just list
    // them with ',' in the order they were created in the original struct
    struct City c2 = {"San Francisco",37,-122};

    // Designated Initializer
    // We set the fields by their names. This is generally Teej's favorite
    //      - its easier to read (has the field names)
    //      - If the fields change, I don't have to worry about breaking the
    //        ordering. Order doesn't matter at this point
    struct City c3 = {
        .name = "San Francisco", // NOTE: its .name not name
        .lat = 37,
        .lon = -122, // NOTE: the trailing comma is allowed here
    };

    // Now how do we access these fields? with '.' (or later we'll see ->)
    c.lat = 41; // setting latitude for the first struct c
    c.lon = -122; // ditto
    c.name = "San Francisco"; // ditto

    printf("Struct C:\n\tName: %s\n\tLatitude: %d\n\tLongitude: %d\n\n",
            c.name,c.lat,c.lon);
    printf("Struct C2:\n\tName: %s\n\tLatitude: %d\n\tLongitude: %d\n\n",
            c2.name,c2.lat,c2.lon);

    // Using the new_coord function 
    struct Coordinate my_new_coord = new_coord(10,20,30);
    printf("Struct Coordinate:\n\t"
           "X: %d\n\t"
           "Y: %d\n\t"
           "Z: %d\n\n",my_new_coord.x,my_new_coord.y,my_new_coord.z);

    return 0;
}

struct Coordinate new_coord(int x,int y,int z)
{
    // first create the "instance" with my struct type
    struct Coordinate coord = {
        .x = x,
        .y = y,
        .z = z,
    };

    return coord;
}
