/**Why a Stack?
 * 
 * Allocating memory on a stack is preferred when possible 
 * because the stack is faster and simpler then the heap (which)
 * I'll get to shortly: 
 *       🔹 Efficient Pointer Management: Stack 'allocation' is just
 *          quick increment or decrement of the stack pointer, whic
 *          is extremely fast. Heap allocations require more complex
 *          bookkeeping
 *       🔹 Cache-Friendly Memory Access: Stack memory is stored in
 *          a contiguou block, enhancing cache performance due to
 *          spatial locality (I remember memory caching with Go)
 *       🔹 Automatic Memory Management: Stack memory is managed 
 *          automatically as functions are called and as they 
 *          return. 
 *       🔹 Inherent Thread Safety: Each thread has its own stack. 
 *          Heap allocations require synchronization mechanisms when 
 *          used concurrently, potentially introducing overhead and
 *          data racing. 
 * All of the above helps me understand  why NASA and Google code
 * using C and C++ the way the do, avoiding the heap when able so
 * memory management is managed by the language constructs and not
 * the programmer. 
 * 
 * One reason Go programs are so efficient is that Go uses stack
 * allocation for variables when possible, much like C. The Go 
 * compiler performs escape analysis to decide whether a variable
 * can be allocated on the stack. On the other hand, languages 
 * like Python allocate most objects on the heap, which can impact
 * peformance. 🤯
 * 
 */

