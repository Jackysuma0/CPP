#include "phonebook.hpp"

int main(int argc, char **argv)
{
    Add addNum;
    int i;
    char *first_name;
    char    *second_name;
    char    *nickname;
    int     *phone_num;
    char    *darkest_secret;

    i = 1;
    if (!strcmp(argv[i], "ADD"))
    {
        cin >> first_name >> second_name >> phone_num >> nickname >> darkest_secret;
        addNum.Add_num(first_name, second_name, phone_num, nickname, darkest_secret);
    }
    else if (!strcmp(argv[i], "SEARCH"))
        search.Search_num();
    else if (!strcmp(argv[i], "EXIT"))
        exit.Exit_func();
    else
        return (0);
    return (0);
}
