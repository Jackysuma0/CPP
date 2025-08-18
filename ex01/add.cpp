#include "phonebook.hpp"

void Add::Add_num(char *first_name, char *second_name, int ph_num, char *darkest_secret)
{
    std::string str = (NULL);
    std::cout << "Please insert the info: " << "\n";
    str += first_name;
    str += " ";
    str += second_name;
    str += " ";
    str += ph_num;
    str += " ";
    str += darkest_secret;
    str += "\n";
    std::cout << str;
    // str.append(first_name);
    // str.append(second_name);
    // str.append(ph_num);
    // str.append(darkest_secret);
}
