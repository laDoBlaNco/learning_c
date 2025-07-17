#include <iostream>

// using namespace std; // we've been using this, but its actually said that we shouldn't use it
// so we don't have naming errors.  So if we comment this out then we just use std with 
// actual calls below

using std::cout;

int main(int argc, char const *argv[])
{
    std::cout << "Hello C++" << std::endl; // must use std::... if not using namepace std
    // or use specific things from namespace

    // so now this works as well
    cout << "hello again";

    return 0;
}