#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    // this->type = getType();
    std::cout << "Cat just appeared out of nowhere." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat decided to leave this place!" << std::endl; 
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy constructor for Cat called." << "\n";
    // *this = other;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Copy assignment operator for Cat called." << "\n";
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Meow meow meow" << std::endl;
}