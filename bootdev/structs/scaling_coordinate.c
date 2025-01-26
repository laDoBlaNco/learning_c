/**Scaling Coordinate
 * 
 * Remembering how I can't return multiple values from a 
 * function in C, and so I can't just return a tuple like I
 * would in python, or just returning multip items like I would in
 * Go.  I can though accomplish basically the same
 * thing returning a struct
 */
#include <stdio.h>
// data structures
struct Human
{
    int age;
    char *name;
};

struct  Coordinate
{
    int x;
    int y;
    int z;
};

// func declarations
struct Human become_older(int,char *);
struct Coordinate scale_coord(struct Coordinate,int);
struct Coordinate new_coord(int,int,int);


int main(int argc, char const *argv[])
{
    struct Human human = become_older(48,"Kevin");
    printf("Struct Human h:\n\t"
           "Name: %s\n\t"
           "Age: %d\n\n",human.name,human.age);   

    // Assignment - Update Coordinate
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

struct Human become_older(int age, char *name)
{
    // again we first initialize our struct
    struct Human h = {
        .age = age,
        .name = name,
    };
    // then we do our action (this kinda makes me think that
    // structs aren't exactly like arrays in that we are still
    // only dealing with a copy here and returning it.)
    h.age++;
    return h;
}

struct Coordinate new_coord(int x,int y,int z)
{
    struct Coordinate coord = {.x=x,.y=y,.z=z};
    return coord;
}

struct Coordinate scale_coord(struct Coordinate coord,int fact)
{
    struct Coordinate scaled_coord = coord;
    scaled_coord.x *= fact;
    scaled_coord.y *= fact;
    scaled_coord.z *= fact;

    return scaled_coord;
}

// My questions  after this remain regarding whether or not we are
// dealing with pointers to fields in structs the same way we are
// with pointers to elements in arrays. And if so, how does that 
// affect the passing by value or reference with structs and in
// turn arrays.
