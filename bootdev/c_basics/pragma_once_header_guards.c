/**Pragma Once and Header Guards
 * 
 * We saw how .h header files are used in a previous lesson, but
 * before we go further let's talk about a potential issue I might
 * run into: multiple inclusions. Very much a PHP thing as well. If
 * the same header file gets included more than once, I can end up 
 * with some nasty errors caused by redefining things like functions
 * or structs.
 * 
 * Pragama Once
 * One simple solution (and the one we'll use for the rest of this
 * course) is #pragma once. Adding this line to the top of a 
 * header file tells the compiler to include the file only once,
 * even if it's referenced multiple times across my program.
 * 
 * // my_header.h
 * #pragma once
 * 
 * struct Point
 * {
 *     int x;
 *     int y;
 * };
 * 
 * Header Guards
 * Another common way to avoid multiple inclusions is with include
 * guards, which use preprocessor directives like:
 * 
 * #ifndef MY_HEADER_H
 * #define MY_HEADER_H
 * 
 * // some cool code
 * 
 * #endif
 * 
 * This method works by defining a unique macro for the header file.
 * If its already been inlcuded, the guard prevents it from being
 * processed again.
 * 
 * Throughout tis course, you'll see #pragma once in the header
 * files. It's quicker and less error-prone than traditional include
 * guards, and it works well with most modern compilers.
 */