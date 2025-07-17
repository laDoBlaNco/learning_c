/**
 * Comments and Output
 * 
 * 
 */

 #include <iostream>

 using namespace std;

 int main()
 {
    // the below gives output <-- these are comments which aren't read by the machine
    // single line comments
    /**
     * multi-line
     * comments
     */
    cout << "Hello world" << endl << "adding something else\n" << endl;

    // back to 'cout' -- console out
    // << means send this to 'cout'
    // endl is for a new line which should only be at the end
    // otherwise i can use \n 
    
    // The C ways still works with 'printf'
    printf("Hello again world\n"); // in cpp, I'll usually use printf only if I want some special
    // formatting which would be easier using the c method
 
 }