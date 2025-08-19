#include <iostream>
#include <sstream>

class Contact
{
    public :
        void set_contact(std::string first, std::string second, std::string nick,
        std::string phone, std::string secret);
        void    print_contact();
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
    private:
            std::string first_name;
            std::string second_name;
            std::string nickname;
            std::string phone_number;
            std::string darkest_secret;
};

class Phonebook
{
    public:
        Phonebook();
        void    add_contact();
        void    search_contact();
    private :
        Contact contacts[8];
        int total_contacts;
};