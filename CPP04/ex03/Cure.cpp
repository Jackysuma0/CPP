#include "Cure.hpp"

Cure::Cure() : AMateria::AMateria("cure")
{
    std::cout << "Cure default constructor called." << std::endl;
    this->_type = AMateria::_type;
}

Cure::~Cure()
{
    std::cout << "Cure default deconstructor called." << std::endl;
}

Cure& Cure::operator=( Cure const &other )
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Cure::Cure( Cure const &other ) : AMateria::AMateria(other)
{
    std::cout << "Cure copy constructor called." << std::endl;
	*this = other;
}

AMateria    *Cure::clone() const
{
    return (new Cure());
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}