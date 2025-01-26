/**Arrays
 * 
 * Focusing back on arrays which are similar to lists in other languages
 * like Python, but really the grandaddy of them all and the base of 
 * many of these other collections. 
 * 
 * An array is a fixed-size, ordered collection of elements. Like lists
 * they are indexed by ints, starting at zero. Unlike lists, they can
 * only hold elements of the same type. They are stored in contiguous
 * memory like structs. But now that I understand pointers clearly
 * I can understand arrays better. 
 * 
 * Iterating over an Array:
 * In C, there is no for..in or for..of, etc. Instead I must iterate
 * over them using the original for loop with an index (or some other
 * conditiona loop, like while or do..while)
 * 
 * Updating Values in an Array
 * The syntax for updating values in an array is the same as I use
 * to access them, with the [] index
 * arr[index] = value
 * 
 * NOTE: From the assignment is good to note that I'm not working
 * with a copy here. I'm changing values of the original array
 * directly from in the function. Enter stage left, Arrays are just pointers!
 */

#include <stdio.h>
// INTERESTING: We have to put the 'filedata[200]' in the declaration
// or I get an error. With this declaration the compiler is expecting a
// pointer and this is how I tell it either puting the actual paramenter
// identifier filetype[200], or as I did int * pointer type. The reason being
// that our first arg is an array OR A POINTER to int
void update_file(int *,int,int);

int main(int argc, char const *argv[])
{
    int numbers[5] = {1,2,3,4,5};

    // updateing a couple elements
    numbers[1] = 20;
    numbers[3] = 40;

    // iterate and print each element
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",numbers[i]);
    }
    printf("\n");    

    //=====================================================
    // Assignment
    int datafile[200] = {0}; // set my array of 200 indexes to zero
    for (int i = 0; i < 200; i++)
    {
        datafile[i] = 69;
    }
    update_file(datafile,11,77);
    for (int i=0;i<200;i++){
        printf("%d\n",datafile[i]);
    }
    
    return 0;
}

void update_file(int filedata[200],int new_filetype,int new_num_lines)
{
    filedata[1] = new_num_lines;
    filedata[2] = new_filetype;
    filedata[199] = 0;
}
// So again at the end of this lesson and especially with what I'm seeing
// with the parameters and args, an array is just a pointer. and when
// I talk about arrays, the C compiler is expecting a pointer to work
// with.
