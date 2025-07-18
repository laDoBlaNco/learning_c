/*
First cpp program for this course

*/

#include <iostream> // the header input out stream
// the #include is a preprocessor directive. The preprocessor takes our code and processes all of the
// lines that start with #. In this example it replaces these lines with the header code

using namespace std;  // the namespace. A better practice would be to use the explicit std::cout

int main()
{
    // this is the principal function
    cout << "GeeksForGeeks" << endl; // cout and endl are objects from 'std' declared in <iostream>
    return 0;
}