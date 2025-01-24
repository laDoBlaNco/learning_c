/**
 * As a dev, it pays to be lazy $$$. What does that mean? If I find myself
 * typing code that performs the same action over and over again, then I need
 * to change something. instead, organize the code into a block that can be reused
 * in other places in my codebase, and then only use that block. This is call the
 * DRY principle, meaning DON'T REPEAT YOURSELF. We do that with functions in C
 * 
 * FUNCTIONS - 
 * Function in C are a block of code that is separated from the rest of the code
 * and performs one logical task. The function I've been using so far is the 'main'
 * function, which is expected by my compiler as the starting point of my programs.
 * 
 * MAKING MY OWN FUNCTIONS - 
 * When I find a logical piece of code that can be extracted and seperated into
 * its own block of code to be re-used, I should turn that into a funtion. I remember
 * with studying Go and JS and some others whenever the instructor repeated code he
 * would put it in its own function to start using. We do that with the
 * following syntax. 
 * 
 * NOTE: in C there's something called function declarations which are basically
 * function prototypes, but not the actual definition. I'll need to learn where to
 * and not use those in the future. Why are they needed, etc? 🤔
 */

// return_type name(parameter list) {..code..}
#include <stdio.h>

int add(int x, int y)
{
    int z = x+y;
    return z;
}

int main()
{
    int ans = add(1,2);
    printf("%d\n",ans);

    return 0; // successful exit code
}

/** So what does return do?
 * When a function is ran, at some point we want the function to go back where
 * function was called and continue the  original path. Doing this is called
 * "returning" (that's one way to think if it 🤔 ) To get a value put into a var
 * as a result of the function, some functions (most functions) return a 'value'.
 * Above add returns an integer and is stored in var ans in main func.
 * 
 * NAMING AND STYLE - 
 * It is expected that a function will perform one logical thing. For our 
 * Database Project, we will create a whole slew of functions that do one simple
 * thing. The name should clearly describe what the function does. If I found my
 * function doing multiple logical things, I should probably either change the logic
 * or the name of the function. 
 */
