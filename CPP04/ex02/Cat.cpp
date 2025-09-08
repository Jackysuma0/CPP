#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    // this->type = getType();
    _ideas = new Brain();
    std::cout << "Cat just appeared out of nowhere." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat decided to leave this place!" << std::endl;
    delete ( _ideas );
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy constructor for Cat called." << "\n";
    _ideas = new Brain();
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

std::string Cat::getIdeas( int pos ) const
{
    return (_ideas->getIdeas(pos));
}

void    Cat::setIdeas( std::string idea, int pos )
{
    _ideas->setIdeas ( idea, pos );
}