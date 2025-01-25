/**Constants
 * 
 * So a vars value can change as long as its type is the same. but 
 * if we don't want it to change then we just make it a const. There
 * are two ways to do this in C
 *  1. const
 *  2. #define
 */

int main(int argc, char const *argv[])
{
    const int x = 5;
    // x = 10;  // error - Assignment of read-only variable 'x'
    return 0;
}
