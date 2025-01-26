/**Typedef
 * 
 * I read this before but after writing all this struct code I'm 
 * definitely getting tired of writing all the struct boilerplate
 * 
 * So how can I make the structs easier to write with just a normal
 * type name?  This is done with typedef
 * 
 * Now below I can use pastry_t whereever I needed to put struct Pastry
 * before as the actual name of my struct type. NOTE: the _t is convention
 * to indicate that this is an actual 'type', I could actually skip
 * over the giving it a name 'Pastry' as its optional
 * 
 * Teej doesn't advise on doing it this way. In general the actual name
 * is helpful I guess if we need to refer to the type somewhere in a different
 * manner???, But typically we only use the typedef'd type
 */

#include <stdio.h>

// struct Pastry
// {
//     char *name;
//     float weight;
// };

// this can also be written like this
// typedef struct Pastry
// {
//     char *name;
//     float weight;
// } pastry_t;

// same as above but without the optional struct name
typedef struct
{
    char *name;
    float weight;
} pastry_t;

// Coordinate struct using type def
typedef struct Coordinate
{
    int x;
    int y;
    int z;
} coord_t;

// funtion declarations to work with  my coordinate
// so everywhere I would normally use 'struct Coordinate' as the type
// I can use coord_t???

// coord_t would be my return type and my arg type
coord_t new_coord(int,int,int);
coord_t scale_coord(coord_t,int);


int main(int argc, char const *argv[])
{
    // Assignment update the Coordinate struct to use typedef
    struct Coordinate coord = new_coord(15,30,45);
    struct Coordinate coord_scaled = scale_coord(coord,1000);
    printf("Struct Coordinate Coord: \n\t"
           "X: %d\n\t"
           "Y: %d\n\t"
           "Z: %d\n\n",coord.x,coord.y,coord.z);
    printf("Struct Coordinate Scaled Coord: \n\t"
           "X: %d\n\t"
           "Y: %d\n\t"
           "Z: %d\n\n",coord_scaled.x,coord_scaled.y,coord_scaled.z);    

    return 0;
}

coord_t new_coord(int x, int y, int z)
{
    coord_t coord = {.x=x,.y=y,.z=z};
    return coord;
}

coord_t scale_coord(coord_t coord, int fact)
{
    coord_t coord_scaled = coord;
    coord_scaled.x *= fact;
    coord_scaled.y *= fact;
    coord_scaled.z *= fact;

    return coord_scaled;
}

// my questions after this lesson have to do with the random numbers
// I get when accessing memory or better said vars not defined or 
// not initialized. but according to this question, seems like just
// something the C implementation does to allocate memory and give
// it junk data to hold the space???

// https://stackoverflow.com/questions/4434948/why-variables-start-out-with-random-values-in-c







