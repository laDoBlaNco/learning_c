/**Struct Padding
 * 
 * There are a bunch of complicated rules and heuristics that different
 * compilers use to determine how to lay out the structs. But I can
 * oversimplify it with the following:
 * 
 *  1. The fields of a struct are laid out in memory continguously
 *     (next to each other)
 *  2. Structs can vary in size depending on how they are laid out.
 * 
 * C is a language that aims to give tight control over memory, so that
 * fact that I can control the layout of my structs is a feature, not
 * a bug.
 * 
 * Compilers + modern hardware + optimizations + skill issues means 
 * that sometimes what I think the computer is going to do isn't 
 * exactly what it actually does. That said, C is designed to get
 * me close to the metal or the machine and allow me to dig in and
 * figure out what's going on if I want to for a specific compiler
 * or arch.
 * 
 * As a rule of thumb, ordering my fields from largets to smallest
 * will help the compiler minimize padding by itself.
 * 
 *  Let's see some of the comparisons down below:
 */

#include <stdio.h>

typedef struct
{
    char a;
    double b;
    char c;
    char d;
    long e;
    char f;
} poorly_aligned_t;

typedef struct 
{
    double b;
    long e;
    char a;
    char c;
    char d;
    char f;
} better_t;

typedef struct 
{
    char type;
    char *name;
    int value;
    char is_constant;
    int  scope_level;

} sneklang_var_t;

typedef struct 
{
    char *name;
    int value;
    int  scope_level;
    char type;
    char is_constant;
} sneklang2_var_t;

int main(int argc, char const *argv[])
{
    printf("Poorly aligned poorly_aligned_t: %zu bytes\n",sizeof(poorly_aligned_t));
    printf("Better aligned better_t: %zu bytes\n",sizeof(better_t));
    printf("\n");
    printf("Poorly aligned sneklang_var_t: %zu bytes\n",sizeof(sneklang_var_t));
    printf("Better aligned sneklang2_var_t: %zu bytes\n",sizeof(sneklang2_var_t));
    return 0;
}
