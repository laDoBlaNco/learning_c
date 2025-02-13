#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*fgets() in C
    
    The fgets function is a reliable way to read strings, especially when
    dealing with inputs containing spaces. Unlike scanf(), which stops
    reading at spaces, fgets() reads the entire string, including spaces
    up to a specified length. That protects us from buffer  overflow as 
    well.
    
    Syntax:
    fgets(name,len,stream)
    
    where, 
        ▫️ name: Name of the string var where the input string will be stored
        ▫️ len: Length upto which the string is to be read
        ▫️ stream: Input stream, often stdin (standard input)
        
    In C, strings are null terminated, meaning an additional character \0
    is added to the end of the string. So, len parameter should always be
    1+ the desired size and it includes the space for the null terminator
    
    fgets() for User Input
    Originally, fgets() was designed to read input from files. However, by
    providing stdin as the input stream, it can read from standard input,
    like user input from the keyboard. This makes it versatile for various
    use cases:*/

    // char name[100];
    // printf("Please enter your full name: \n");
    // fgets(name, 100, stdin);
    // printf("Hi %s,\n",name);
    // printf("Welcome to GfG!\n");

    /*Why use fgets()
    In the past, the gets() function was commonly used to read strings,
    but it was considered unsafe. It lacked a mechanism to limit the
    number of characters being read, which could lead to buffer overflows
    and make programs vulnerable to attacks. For this reason, gets() has
    been deprecated in modern version of C
    
    The fgets() function addresses these issues by allowing programmers
    to specify the max number of chars to read, inluding the null
    terminator. This safety feature makes it preferred choice for reading
    strings.*/


    return 0;
}
