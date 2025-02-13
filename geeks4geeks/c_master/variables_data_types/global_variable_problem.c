#include <stdio.h>

int g = 10;

int main(int argc, char const *argv[])
{

    /*Initialize a global variable g having int type and value as
    10. 
    
    NOTE: this variable is used in the main function, so I don't 
    need to change that. */
    printf("%d\n", g);

    return 0;
}
