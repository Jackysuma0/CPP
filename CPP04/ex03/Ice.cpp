#include "Ice.hpp"

Ice::Ice() : AMateria::AMateria("ice")
{
    std::cout << "Ice default constructor called." << std::endl;
    this->_type = AMateria::_type;
}

Ice::~Ice()
{
    std::cout << "Ice default deconstructor called." << std::endl;
}

Ice& Ice::operator=( Ice const &other )
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Ice::Ice( Ice const &other ) : AMateria::AMateria(other)
{
    std::cout << "Ice copy constructor called." << std::endl;
	*this = other;
}

AMateria    *Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}