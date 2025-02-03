/**Checking for Errors with errno
 * 
 * When I call a function that I didn't write, and specifically that
 * I don't know the internals of, sometimes that function might fail. 
 * We as developers need to know what went wrong, and if the failure
 * is our fault. Enter: errno
 * 
 * errno
 * If a function that you call returns the error value for that
 * function as described in the RETURN VALUE section of the man page,
 * I can ask the function what specifically went wrong by asking for
 * the errno. Errno is a global value in glibc that is used to give
 * the developer information about what went wrong when a function
 * fails. 
 * 
 * Man pages again: 
 * At the bottom of a man page is the description for all of the 
 * errors that can occur in every function. Check out the example
 * below:
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd = open("./file_that_dont_exist",O_RDONLY);
    if (fd == -1 ) {
        perror("open");
        return -1;
    }
    return 0;
}

// so this code uses a glibc function 'open' to try to open a file
// This will ultimately fail. I can use perror to ask glibc to print
// out the error string for what specifically went wrong with that
// function call so that I can take corrective action. I can also 
// check the manpage to read about what could have went wrong based
// on the errno value


