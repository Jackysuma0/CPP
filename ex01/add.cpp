#include "phonebook.hpp"

Add::Add(int number)
{
    phone_num = number;
    string = new char[10]();
}

Add& Add::operator