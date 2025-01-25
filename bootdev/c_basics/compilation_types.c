/** Compilation Types: 
 * 
 * I'm already familiar with the idea of types and C does them quite 
 * a bit differently. But again, if C came first then I would argue that its
 * Python that does them differently 🤔
 * 
 * In python you can change the type of a variable, but in C changing
 * the type of an existing var is not allowed. 
 * 
 */

int main(int argc, char const *argv[])
{
    char *max_threads = "5";

    max_threads = 5;
    return 0;
}

// it did allow me to compile, though with a warning "int-conversion assignment
// to 'char *' from 'int' makes pointer from integer without a cast"