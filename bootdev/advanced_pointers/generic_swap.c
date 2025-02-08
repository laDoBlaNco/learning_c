/** Generic Swap
 * 
 * So for the  previous swap implementations I already knew the type
 * that I wanted to swap (*int or **char). Since I knew the type, the
 * compiler knew the size of the data that we wanted to swap. 
 * 
 * However, if I want to make a GENERIC SWAP, meaning I don't know 
 * the size ahead of time, i'll need to use the generic pointer void*
 * and that means I'll need to then provide the compiler with the size 
 * of the data that I'm swapping since the the void* loses all the type
 * info. My new interface for swap will need to include the size info.
 * 
 * Now the other problem I'll have is that directly assigning pointer
 * values doesn't work the same way with void*. Instead of using: 
 *      *ptr1 = *ptr2 
 * I will need to use 'memcopy' which is part of the string.h header
 *      void *memcpy(void *destination, void *source, size_t size);
 * Just like malloc it looks like it returns a void*
 * 
 * So to move the data it would be:
 *      memcpy(ptr1, ptr2, size);
 * 
 * The Assignment:
 * Implement the generic swap function: 
 *  1. Allocate memory for a temporary buffer to store the data 
 *     using malloc
 *  2. If the allocation fails (returns NULL) return immediately
 *  3. Use memcpy to shuffle the data around
 *  4. Don't forget to free the temporary buffer 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct {
    uint64_t quality;
    uint64_t taste;
    uint64_t branding;
} coffee_shop_t;

void swap(void*,void*,size_t);

int main(int argc, char const *argv[])
{
    printf("\nTest #1 (test_generic_ints):\n");
    int i1 = 1234;
    int i2 = 5678;
    printf("i1 is currently %d\n",i1);
    printf("i2 is currently %d\n",i2);
    swap(&i1, &i2, sizeof(int));
    printf("i1 should now be 5678 and it is %d\n", i1);
    printf("i2 should now be 1234 and it is %d\n",i2);

    printf("\nTest #2 (test_generic_strings)\n");
    char *s1 = "dax";
    char *s2 = "adam";
    printf("s1 is currently %s\n",s1);
    printf("s2 is currently %s\n",s2);
    swap(&s1, &s2, sizeof(int));
    printf("s1 should now be 'adam' and it is %s\n", s1);
    printf("s2 should now be 'dax' and it is %s\n", s2);

    printf("\nTest #3 (test_generic_structs)\n");
    coffee_shop_t sbucks = {2,3,4};;
    coffee_shop_t terminal_shop = {10,10,10};
    // compiler told me to change %d to %ld since these fields are uint64s
    printf("sbucks.quality is currently %ld\n", sbucks.quality);
    printf("sbucks.taste is currently %ld\n",sbucks.taste);
    printf("sbucks.branding is currently %ld\n",sbucks.branding);
    printf("terminal_shop.quality is currently %ld\n", terminal_shop.quality);
    printf("terminal_shop.taste is currently %ld\n",terminal_shop.taste);
    printf("terminal_shop.branding is currently %ld\n",terminal_shop.branding);
    // NOTE: there was a bug here. sizeof needs to be sizeof(coffe_shop_t) But I 
    // left it at sizeof(int) thinking that the resulting %ld was needed. But swap
    // is moving the struct not just the field. That's why it didn't have room for
    // all 3 fields and only swapped the first.
    // swap(&sbucks, &terminal_shop, sizeof(int));
    swap(&sbucks, &terminal_shop, sizeof(coffee_shop_t));
    printf("sbucks.quality should now be 10 and is %ld\n", sbucks.quality);
    printf("sbucks.taste should now be 10 and is %ld\n",sbucks.taste);
    printf("sbucks.branding should now be 10 and is %ld\n",sbucks.branding);
    printf("terminal_shop.quality should now be 2 and is %ld\n", terminal_shop.quality);
    printf("terminal_shop.taste should now be 3 and is %ld\n",terminal_shop.taste);
    printf("terminal_shop.branding should now be 4 and is %ld\n",terminal_shop.branding);




    return 0;
}

void swap(void* vp1,void* vp2,size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) return;
    memcpy(ptr,vp1,size);
    memcpy(vp1,vp2,size);
    memcpy(vp2,ptr,size);

    free(ptr);
}

