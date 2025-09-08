#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    // this->type = getType();
    std::cout << "Dog chose you as his new owner." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog decided to leave this place!" << std::endl; 
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy constructor for Dog called." << "\n";
    // *this = other;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Copy assignment operator for Dog called." << "\n";
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Bark bark bark !" << std::endl;
}