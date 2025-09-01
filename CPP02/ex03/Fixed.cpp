#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    // std::cout << "Default constructor called" << "\n";
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << "\n";
}

Fixed::Fixed(const Fixed& other)
{
    // std::cout << "Copy constructor called" << "\n";
    value = other.value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignment operator called" << "\n";
    if (this != &other)
    {
        value = other.value;
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << "\n";
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed::Fixed(const float f)
{
    // std::cout << "Float constructor called" << "\n";
    value = static_cast<int>(roundf(f * (1 << bits)));
}

float   Fixed::toFloat() const
{
    return (static_cast<float>(value) / (1 << bits));
}

Fixed::Fixed(const int n)
{
    // std::cout << "Int constructor called" << "\n";
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

int Fixed::operator>( const Fixed& other)
{
    return (getRawBits() > other.getRawBits());
}

int Fixed::operator<( const Fixed& other)
{
    return (getRawBits() < other.getRawBits());
}

int Fixed::operator<=( const Fixed& other)
{
    return (getRawBits() <= other.getRawBits());
}

int Fixed::operator>=( const Fixed& other)
{
    return (getRawBits() >= other.getRawBits());
}

int Fixed::operator==( const Fixed& other)
{
    return (getRawBits() == other.getRawBits());
}

int Fixed::operator!=( const Fixed& other)
{
    return (getRawBits() != other.getRawBits());
}

Fixed   Fixed::operator+( const Fixed& other )
{
    return (Fixed( toFloat() + other.toFloat()));
}

Fixed   Fixed::operator-( const Fixed& other )
{
    return (Fixed( toFloat() - other.toFloat()));
}

Fixed   Fixed::operator*( const Fixed& other )
{
    return (Fixed( toFloat() * other.toFloat()));
}

Fixed   Fixed::operator/( const Fixed& other )
{
    return (Fixed( toFloat() / other.toFloat()));
}

Fixed   Fixed::operator++( void )
{
    setRawBits ( getRawBits() + 1);
    return (*this);
}

Fixed   Fixed::operator--( void )
{
    setRawBits ( getRawBits() - 1);
    return (*this);
}

Fixed   Fixed::operator--( int i)
{
    Fixed fix(*this);

    (void)i;
    setRawBits(getRawBits() - 1);
    return (fix);
}

Fixed   Fixed::operator++( int i)
{
    Fixed fix(*this);

    (void)i;
    setRawBits(getRawBits() + 1);
    return (fix);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    return ((a < b) ? a : b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    return ((a > b) ? a : b);
}

const Fixed&    Fixed::min(const Fixed& a, const Fixed&b)
{
    return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

const Fixed&    Fixed::max(const Fixed& a, const Fixed&b)
{
    return ((a.getRawBits() > b.getRawBits()) ? a : b);
}