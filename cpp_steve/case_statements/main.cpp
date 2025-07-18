/**
 * Case Statements
 *
 * so as expected the case statement replaces if statement chains. Works as I would expect
 * For now it looks like it only works with integers and enums, not chars or strings, 
 * but Steve is only guessing, so I'll come back to this.
 */

#include <iostream>

int main()
{
    int dayOfWeek = 8;
    std::string day;

    switch (dayOfWeek)
    {
    case (1):
        day = "Mon";
        break;
    case (2):
        day = "Tue";
        break;
    case (3):
        day = "Wed";
        break;
    case (4):
        day = "Thu";
        break;
    case (5):
        day = "Fri";
        break;
    case (6):
        day = "Sat";
        break;
    case (7):
        day = "Sun";
        break;
    default:
        day = "not a day";
    }

    std::cout << "Today is " << day << std::endl;
}