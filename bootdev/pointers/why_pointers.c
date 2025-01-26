/**Why Pointers?
 * 
 * So just to illustrate why I need to use pointers and that they are
 * useful, let's pretend that I want to pass a collection of data into
 * a function. Within that function, I want to modify the data. In
 * Python, we could use a class to store the data, and pass an instance
 * of that class into the function. 
 * 
 * Python:
 *  Class Coordinate:
 *      def __init__(self,x,y,z):
 *          self.x = x
 *          self.y = y
 *          self.z = z
 * 
 *  def update_coordinate_x(coord,new_x):
 *      coord.x = new_x
 * 
 * c = Coordinate(1,2,3)
 * update_coordinate_x(c,4)
 * 
 * ...More or less
 * 
 * 
 * If I do the same thing below in C with a struct, I see something
 * different. 
 * 
 * As seen below, after running both functions notice that coord_update_x
 * didn't really update anything, but coord_update_and_return did because it
 * RETURNED a new COPY of my struct
 * 
 * Remember:
 *      - In C, structs are passed by value (copies). That's why updating
 *        a field in a struct does not change the original struct from 
 *        the main function.
 *      - To get the change to 'persist', I needed to return the updfated
 *        copy of my struct from the function
 *      - The memory address of the struct that went in to coord_update_and_return
 *        was not the same as the address of teh struct that was returned. Again,
 *        because we created and actually worked on a copy. 
 */
#include <stdio.h>

typedef struct Coordinate
{
    int x;
    int y;
    int z;
} coord_t;

void coord_update_x(coord_t,int);
coord_t coord_update_and_return(coord_t,int);

int main(int argc, char const *argv[])
{
    coord_t test_coord = {15,30,45};
    coord_update_x(test_coord,60);
    coord_t test_coord2 = coord_update_and_return(test_coord,60);

    printf("Test Coordinate:\n\t"
           "X: %d\n\t"
           "Y: %d\n\t"
           "Z: %d\n\n",test_coord.x,test_coord.y,test_coord.z);

    printf("Test Coordinate #2:\n\t"
           "X: %d\n\t"
           "Y: %d\n\t"
           "Z: %d\n\n",test_coord2.x,test_coord2.y,test_coord2.z);

    return 0;
}

void coord_update_x(coord_t coord, int new_x)
{
    coord_t updated = coord;
    updated.x = new_x;
    return;
}

coord_t coord_update_and_return(coord_t coord, int new_x)
{
    coord_t updated = coord;
    updated.x = new_x;
    return updated;
}
