#include <algorithm>
#include <cstring>
#include <iostream>

class Add
{
    public:
        void Add_num(char *first_name, char *second_name, int ph_num, char *darkest_secret);
        char *first_name;
        char    *second_name;
        char    *nickname;
        int     *phone_num;
        char    *darkest_secret;
        // ~Add();
    private:
        int phone_num;
        char * string;
};

class Exit
{

};

class Search
{
    public:
        char * Contact;
};
