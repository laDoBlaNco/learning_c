/**What is glibc
 * 
 * So far, we've just about covered all of the features of the
 * C programming language has to offer. You could be thinking...
 * no way that's possible. Well, it is. The C programming language
 * itself is incredibly simple. The power of the language comes
 * from its simplicity and the control it leaves to the developer
 * 
 * You've probably also noticed that we used a few magical functions
 * that we didn't write ourselves. These functions come from a library
 * that we'll talk about in this section. 
 * 
 * Glibc
 * Glibc, or the GNU C library, is the library that gets baked into
 * every program I compile with gcc. This concept is important to
 * understand because it will be the foundation of every program
 * I write, and as a result I should understand GNU C library
 * functionality
 * 
 * Why
 * When I write code, I write userland code, or code that exists in
 * the context of a userspace process. To the CPU, this code is
 * underpriveleged, and as a result it can't really do anything
 * fancy, like allocate memory, access the filesystem, or access
 * the network. 
 * 
 * To do privileged things, I have to ask the kernel (which runs as
 * priveleged code) to do it for us. This is done through what is
 * called a "system call interface" where the syscall instruction
 * is ran, and asks the kernel to perform a certain action. 
 * 
 * The GNU C library cleanly wraps all of this functionality up into
 * easy to use functions that wrap the otherwise hard to maintain
 * system call functionality
 * 
 * Malloc
 * One example of these is how I allocate memory from the kernel
 * for our processes, I use malloc. Malloc internally calls sbrk
 * and mmap system calls, which asks the kernel through a system
 * call to give us more memory. All of this is abstracted away from
 * us as the developer, and all we have to do is manage the result. 
 * 
 * We can see what libraries are linked against our program with
 * ldd ./my_program
 * 
 */