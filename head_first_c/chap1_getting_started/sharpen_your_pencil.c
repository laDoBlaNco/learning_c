/*
Sharpen Your Pencil - try to guess what these will do before running the code
*/

#include <stdio.h>

int main(){
    int card_count = 11;
    
    if(card_count > 10){
        puts("The deck is hot. Inrease bet.");
    }
    // the above will print whats in 'puts' cuz card_count is 11 - 
    puts("");

    int c = 10;
    while (c > 0)
    {
        puts("I must not write code in class");
        c-=1;
    }
    // this will print from 10 down to 1
    puts("");

    char amor[20];
    puts("Enter wife's name: ");
    scanf("%19s",amor);
    printf("Dear %s.\n\n\tI love you!!!\n",amor);
    // this will ask for my wife's name and after I input it nad hit enter it prints the message
    // instresting %19s in scanf will only scan for that many chars. Good secure programming
    puts("");

    char suit = 'H';
    switch(suit)
    {
        case 'C':puts("Clubs");break;
        case 'D':puts("Diamonds");break;
        case 'H':puts("Hearts");break;
        default:puts ("Spades");
    }
    // this will look at the value of suit and print the result according to what the value is
    


}

