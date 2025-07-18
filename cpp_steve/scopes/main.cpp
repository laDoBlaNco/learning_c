/**
 * Scopes:
 * 
 * Pretty much normal. Global scope variables are visible everywhere while local scope variables
 * are visible in their scope or their block and they will shadow higher scoped vars.
 * 
 * One thing thats specific to cpp is using the ::var to actual tell cpp to use the global scope
 * variable
 */

 #include <iostream>

int x = 15;
int y = 15;

int sum(int num1, int num2)
{
    int x = num1;
    return x + num2;
}

 int main(int argc, char* argv[])
 {
    int x = 20;
    std::cout << sum(::x,y) << std::endl; // here using ::var

    return 0;
 }