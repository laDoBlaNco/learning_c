/**Virtual Memory
 * 
 * So as it turns out, my code probably doesn't have direct access
 * to the physical RAM memory on my computer. I know it said we are
 * down to the metal, but in reality that's a good thing. It would
 * be like touching the computer with my big fat greasy fingers. 
 * Its better to have some kinda protection and that's the virtual 
 * memory. 
 * 
 * Instead, my OS provides a layer of abstraction called virtual memory
 * Virtual memory makes it seem like my program has direct access to
 * all the memory on the machine but in reality and thankfully I 
 * do not.
 *      - Physical Memory: The actual RAM sticks on my computer
 *      - Operating System: The software that manages access to the
 *        physical memory
 *      - My program: When it runs, it becomes a process and is given
 *        access to a chunk of virtual memory by the operating system
 *      - Virtual Memory: The abstracted chunk of memory that my 
 *        program can use.
 * 
 * There are exceptions to this, for example if I'm using C to build
 * embedded firmware, which I plan on doing someday, that will run
 * without out an operating system, so my code might interact directly
 * with the physical memory.
 * 
 * By only giving processes access to a chunk of virtual memory, the
 * operating system can do some cool things:
 *      1. Isolation: One process can't access memory of another 
 *      2. Security: The operating system can prevent processes from
 *         accessing certain parts of the memory
 *      3. Simplicity: Developers don't have to worry about managing
 *         physical memory and the memory of other processes.
 *      4. Performance: The OS can optimize memory access depending
 *         on the hardware and needs of the program. For example, by
 *         moving data between physical memory and the hard drive.
 * 
 * At the end of the day, my program has direct access to a virtual
 * chunk of memory. just like physical memory, it can be thought of
 * as a big array of bytes, where each byte has an address. so its 
 * pretty transparent to me.
 */