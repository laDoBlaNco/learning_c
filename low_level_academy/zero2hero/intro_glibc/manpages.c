/**How to read a manpage
 * 
 * The lesson is to understand the importance and power of man
 * pages. 
 * 
 * Man
 * When I write code in C, I will depend heavily on function that 
 * I didn't write. And as any good developer knows, when you depend
 * on somone elses code base, its really important that they have 
 * documentation. Man pages are the documentation for these functions
 * 
 * 'man malloc' for example
 * 
 * Function Prototype
 * In a manpage, I see a couple of things. The first is the prototype
 * whcih describes the types expected to be used in the function 
 * parameters and return value. This is extremely important to know
 * because confusing the return types from functions can lead to
 * memory corruption issues if not handled correctly. Also, the
 * function expects for the parameters to be shaped a certain way. 
 * 
 * Function Description
 * Next, the function will describe what it does. PLEASE READ THESE
 * There are so many programmers who THINK they know what a function
 * does just based on the name of the function. And most of the time
 * they're correct, BUT it's extremely common for edge cases to
 * arise in tehse functions and when encountered, can lead to a 
 * crash or security failure. Understand what the function does. 
 * 
 * Function Return Value
 * The return value will tell you what the expected return value
 * is in a good state or an error state. it's extremely important
 * to always check your return values to see if an error occured. 
 */