#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    // this->type = getType();
    std::cout << "WrongCat just appeared out of nowhere." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat decided to leave this place!" << std::endl; 
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Copy constructor for WrongCat called." << "\n";
    // *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Copy assignment operator for WrongCat called." << "\n";
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "I am a suspicious cat." << std::endl;
}