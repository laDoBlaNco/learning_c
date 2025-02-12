#include <stdio.h>
#include <stdbool.h>

int main()
{
    int age = 42;
    char name[] = "ladoblanco";
    float weight = 260.5;
    bool married = true;
    char gender = 'm';
    
    printf("%d \n", age);
    printf("%s \n", name);
    printf("%f \n", weight);
    printf("%d \n", married); // 'true or false' can only be used with stdbool.h
    // but the result still just 1=true and 0=false
    printf("%c \n", gender);
}