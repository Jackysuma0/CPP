#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << "\n";
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n";
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << "\n";
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << "\n";
}

void    Harl::complain(std::string level)
{
    int     i;
    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    i = 0;
    while (i < 4)
    {
        if (str[i] == level)
        {
            break ;
        }
        i++;
    }
    switch(i)
    {
        case 0:
            this->debug();
            break ;
        case 1:
            this->info();
            break ;
        case 2:
            this->warning();
            break ;
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
            break ;
    }
}