#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;//holds the memory address of the object
    std::string& stringREF = str;//cant be null, only points to one object, shares memory address of the object

    std::cout << "Value of the string variable: " << str << "\n";
    std::cout << "Value if the pointer: " << *stringPTR << "\n";
    std::cout << "Value of the reference: " << stringREF << "\n";

    std::cout << "Address of the string variable: " << &str << "\n";
    std::cout << "Address of pointer: " << stringPTR << "\n";
    std::cout << "Address of reference: " << &stringREF << "\n";
    return (0);
}