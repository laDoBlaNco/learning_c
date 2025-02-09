/**Garbage Collector
 * 
 * So up until now I've been manually managing memory throughout this 
 * course with my c code. However, Sneklang, the language I'm building
 * here in this example, has automatic memory management. Specifically
 * it makes use of a garbage collector. 
 * 
 *  ▫️ In C and C++, management of heap memory is done manually with
 *    malloc and free (and new and delete in C++)
 *  ▫️ Rust has a compile-time system that ensures memory safety
 *  ▫️ Zig gives the programmer access to "allocators" to manage
 *    memory. 
 * 
 * These are all examples of "manuel memory management" -- the 
 * programmer has to write code that keeps track of and frees 
 * memory. 
 * 
 * So What's a Garbage Collector?
 * 
 * A garbage collector is aa program (or part of a program) that 
 * automatically frees memory that is no longer in use. Languages like
 * Python, Java, JavaScript, OCaml, and even Go use garbage collection
 * as the code is running to manage memory. It's "automatic memory
 * managemenet". Automatic memory management can be a huge productivity
 * boost for developers (less code, and sometimes fewer memory-related
 * bugs) but it typically comes with a performance cost because 
 * like Forrest Gump, the garbage collector is always running. 
 * 
 * It's no coincidence that C, C++, Rust, and Zig are all great 
 * choices when you need to squeeze every last drop of performance
 * out of your code.
 */