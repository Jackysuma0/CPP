#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << "\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << "\n";
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << "\n";
    value = other.value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << "\n";
    if (this != &other)
    {
        value = other.value;
    }
    return (*this);
}

int Fixed::getRawBits( void )
{
    std::cout << "getRawBits member function called" << "\n";
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}