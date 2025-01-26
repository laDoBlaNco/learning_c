/**Multibyte Arrays
 * 
 * So WTH is a multibyte array? If I create an array of structs
 * it gets kinda crazy because now I can access and manipulate
 * the elements using eiher indexing or pointer arithmetic. 
 * 
 * Let's see how these multi-byte width structures are managed in
 * memory.
 * 
 * First I'll start with our Coordinate struct
 * 
 * Then I'll declare an array literal of 3 coord_t structs
 * 
 * Then I can print out the values of the second elemeent with 
 * indexes and (.)
 * 
 * or I can print using pointer arithmetic and (->)
 * 
 * As I can see the difference here is when working with a pointer
 * and of course if we are working with arrays, we are automatically 
 * working with pointers and no need for using & with the array's 
 * identifier.
 * 
 * Memory Layout of our practice below:
 * If I assume each int is 4 bytes, the Coordinate structure will
 * be 12 bytes (3 * 4 bytes). Assuming the points array starts at
 * memory address 0x2000, I can assume the following layout.
 * 
 *      Address	Element	Value	Offset (bytes)
        0x2000	points[0].x	1	0
        0x2004	points[0].y	2	4
        0x2008	points[0].z	3	8
        0x200C	points[1].x	4	12
        0x2010	points[1].y	5	16
        0x2014	points[1].z	6	20
        0x2018	points[2].x	7	24
        0x201C	points[2].y	8	28
        0x2020	points[2].z	9	32
 * 
 * 
 * Accessing Elements Using Pointers
 *      - points+0 or &points[0] points to 0x2000
 *      - points+1 or &points[1] points to 0x200c 
 *        (next structure, offset by 12 bytes)
 *      - points+2 or &points[2] points to 0x2018
 * what I don't understand is that second syntax. How does &points[1]
 * point to the same as points+1. Ok now I get it.  
 * 
 * Since
 *      *(points+2) is the same as points[2] then
 *      points+2 is the same as &points[2]
 * 
 * and since we are talking about an array (pointer) to structs then
 * a each struct is 12bytes contiguous so each element in the array
 * is 12 byte increments
 */
#include <stdio.h>

typedef struct Coordinate
{
    int x;
    int y;
    int z;
} coord_t;

int main(int argc, char const *argv[])
{
    coord_t points[3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    // using indexes and (.):
    printf("points[1].x = %d, points[1].y = %d, points[1].z = %d\n",
           points[1].x,points[1].y,points[1].z);

    // or using ptr arithmetic and (->) IF WORKING WITH A POINTER
    coord_t *ptr = points; // this works cuz its an array, so no '&'
    printf("points[1].x = %d, points[1].y = %d, points[1].z = %d\n",
           (ptr+1)->x,(ptr+1)->y,(ptr+1)->z);


    return 0;
}

