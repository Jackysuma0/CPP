#include "Animal.hpp"

Animal::Animal(const std::string type)
{
    this->type = type;
    std::cout << "Animal with type " << type << " has been created." << std::endl;
}

Animal::Animal() : type("Default")
{
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal with type " << this->type << " has been sent away." << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor for Animal called." << std::endl;
    type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Copy assignment operator for Animal called." << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

// void    Animal::makeSound() const
// {
//     std::cout << "Squick squick squick" << std::endl;
// }

std::string Animal::getType() const
{
    return (this->type);
}

void    Animal::setType( const std::string type_ref )
{
    type = type_ref;
}