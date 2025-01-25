#include <stdio.h>

/**Arrays as Pointers in C
 * 
 * In C, arrays and pointers are closely related. An array name acts
 * as a pointer to the first element of the array. That means array
 * indexing and pointer arithemetic (semantics???) can be used interchangeably
 * What is pointer arithmetic really??? 🤔
 * 
 * Let's go through step and by and see if I understand better and 
 * then after that I'll come back to put my own definition 
 */




int main(int argc, char const *argv[])
{
    // 1. Array declarations - here, numbers is an array of 5 ints
    int numbers[5] = {1,2,3,4,5};

    // 2. The array is a pointer - The name numbers actually acts a
    //    a pointer to the FIRST element of the array
    int *numbers_ptr = numbers;  // So numbers is just an address?? a ptr???
    printf("%p\n",numbers_ptr);
    printf("%p\n",numbers); // this gives me the same thing 🤯🤯🤯

    // so yes, numbers is just a pointer (an address)

    // 3. Accessing Elements via indexing:
    int val = numbers[2]; // accessing the 3rd element with it
    // with is the same as 
    int val2 = *(numbers + 2);

    printf("%d - %d\n",val,val2);
    // so what would that give me memory wise? would it be adding bytes to the address
    printf("%p\n",numbers);
    printf("%p\n",numbers+1);
    printf("%p\n",numbers+2); // interstingly the "+ 1" increases our addres by 4 bits

    // So the array address points to the first element (ptr + 0) and then subsequently
    // (ptr + 1) and (ptr + 2) so the address or ptr moves contiguously with each 
    // element. And I think this opens the door for me into understand pointer arithmetic

    // YES!!!
    // When you add an integer to a pointer, the resulting pointer is offset by that
    // integer times the size of the data type, Thus for me above it was 1*4 or 4 bytes
     
     /* 

        Let's assume numbers is stored starting at memory address 0x1000 .An integer
        is typically 4 bytes in C, So the table belows shows how the ptr arithmetic
        would work and array elements laid out in memory.

        Address	Element	Value
        0x1000	numbers[0]	1
        0x1004	numbers[1]	2
        0x1008	numbers[2]	3
        0x100C	numbers[3]	4
        0x1010	numbers[4]	5
    */

    // some more example code below
    printf("\n");

    // Accessing elements using array indexing
    printf("numbers[2] = %d\n",numbers[2]);

    // accessing elements using pointers
    printf("*(numbers + 2) = %d\n", *(numbers+2));
    printf("\n");

    // pointer arithmetic
    int *ptr = numbers;
    printf("Pointer ptr points to numbers[0]: %d - Address: %p\n",*ptr,ptr);
    ptr+=2;
    printf("Now pointer ptr points to numbers[2]: %d - Address: %p\n",*ptr,ptr);
    
    return 0;
}
