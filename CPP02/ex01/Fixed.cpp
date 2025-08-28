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

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << "\n";
    value = static_cast<int>(roundf(f * (1 << bits)));
}

float   Fixed::toFloat() const
{
    return (static_cast<float>(value) / (1 << bits));
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << "\n";
    value = n << bits;
}

int Fixed::toInt() const
{
    return (value >> bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}