#include "phonebook.hpp"

Phonebook::Phonebook()
{
    total_contacts = 0;
}

void    Contact::set_contact(std::string first, std::string second, std::string nick, std::string phone, std::string secret)
{
    first_name = first;
    second_name = second;
    nickname = nick;
    phone_number = phone;
    darkest_secret = secret;
}

void    Contact::print_contact()
{
    std::cout << "First name: " << first_name << "\n";
    std::cout << "Last name: " << second_name << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone number: " << phone_number << "\n";
    std::cout << "Darkest secret: " << darkest_secret << "\n";
}

void    Phonebook::add_contact()
{
    std::string first, second, nickname, phone, secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first);
    std::cout << "Enter second name: ";
    std::getline(std::cin, second);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, secret);
    if (first.empty() || second.empty() || nickname.empty() || phone.empty() || secret.empty())
    {
        std::cout << "Error: No field can be empty!\n";
        return;
    }
    Contact new_contact;
    new_contact.set_contact(first, second, nickname, phone, secret);
    contacts[total_contacts % 8] = new_contact;
    total_contacts++;
    std::cout << "Contact has beeb added to your phonebook !" << "\n";
}

std::string format_field(const std::string& field)
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    else
        return (std::string(10 - field.length(), ' ') + field);
}

std::string Contact::get_first_name() {
    return first_name;
}

std::string Contact::get_last_name() {
    return second_name;
}

std::string Contact::get_nickname() {
    return nickname;
}

void    Phonebook::search_contact()
{
    int i;

    i = 0;
    std::cout << format_field("Index") << "|"
              << format_field("First Name") << "|"
              << format_field("Last Name") << "|"
              << format_field("Nickname") << std::endl;
    while(i < 8 && i < total_contacts)
    {
        std::stringstream ss;
        ss << i;
        std::cout << format_field(ss.str()) << "|"
                  << format_field(contacts[i].get_first_name()) << "|"
                  << format_field(contacts[i].get_last_name()) << "|"
                  << format_field(contacts[i].get_nickname()) << std::endl;
        i++;
    }
    std::cout << "Enter the index of wanted contact: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.length() == 1 && isdigit(input[0]))
    {
        int index = input[0] - '0';
        if (index >= 0 && index < total_contacts)
        {
            std::cout << "Contact " << index << " detailt:\n";
            contacts[index].print_contact();
        }
        else
        {
            std::cout << "Invalid index: out of range.\n";
        }
    }
    else
        std::cout << "Invalid input: not a digit.\n";
}