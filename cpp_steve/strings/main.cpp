/**
 * Strings
 * In the simplest understanding its a bunch of chars between "" double quotes
 * 
 * we can store strings in string variables with std::string
 * 
 * when working with strings its good to include <string>
 * 
 * cpp has the expected escape chars like \t, \n, etc
 */

 #include <iostream>
 #include <string>

 int main()
 {

    std::string word = "Hello ";
    std::cout << word << "string" << std::endl;

    std::string str = "Ladoblanco ";
    // str+="World";
    str.append("World");
    str.pop_back(); // this removes the last char.
    std::cout << str.length() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str << std::endl;
    std::cout << str.compare("Ladoblanco Worl") << std::endl;
    std::cout << str.substr(0,4) << std::endl;
    std::cout << "\n";

    std::string str2 = "Hello, my name is Kevin, but you can call me Ladoblanco which is my last name in spanish";
    std::cout << str2.find("my") << std::endl;
    std::cout << str2.rfind("my") << std::endl; // reverse find
    std::cout << str2.find_first_of("aeiou") << std::endl;
    std::cout << str2.find_first_not_of("aeiou") << std::endl;
    std::cout << str2.erase(23) << std::endl;
    std::cout << str2 << std::endl; // it actually does erase it, so it mutates my string
    str2.replace(18,5,"Papi");
    std::cout << str2 << std::endl;



    return 0;
 }