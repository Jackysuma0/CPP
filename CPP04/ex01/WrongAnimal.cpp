#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string type)
{
    this->type = type;
    std::cout << "WrongAnimal with type " << type << " has been created." << std::endl;
}

WrongAnimal::WrongAnimal()
{
    this->type = "WRONG";
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal with type " << this->type << " has been sent to the rainbow." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "Copy constructor for WrongAnimal called." << "\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Copy assignment operator for WrongAnimal called." << "\n";
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "*A very suspicious sound from a cat*" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void    WrongAnimal::setType( const std::string type_ref )
{
    type = type_ref;
}