#include "phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
    Phonebook phonebook;
    std::string command;

    std::cout << "Welcome to PhoneBook!\n";
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command.\n";
    }
    return (0);
}
