#include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{
    std::cout << "Default constructor for AMateria was called." << std::endl;
}

// AMateria::AMateria( const std::string type ) : _type(type)
// {
//     std::cout << "Type constructor for AMateria was called." << std::endl;
// }

AMateria::~AMateria()
{
    std::cout << "Default deconstructor for AMateria was called." << std::endl;
}

AMateria::AMateria( const AMateria &other)
{
    std::cout << "Copy constructor for AMateria called." << std::endl;
    _type = other._type;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria base constructor called for type : " << this->_type << "." << std::endl;
}


AMateria& AMateria::operator=( const AMateria &other )
{
    std::cout << "Copy assignment operator for AMateria called." << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
    std::cout << "* uses a mysterious materia on " << target.getName() << " *" << std::endl;
}