#include <iostream>
#include <cmath>

class   Fixed
{
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        int    getRawBits( void ) const;
        void    setRawBits( int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;

        Fixed   operator+(const Fixed& other);
        Fixed   operator-(const Fixed& other);
        Fixed   operator*(const Fixed& other);
        Fixed   operator/(const Fixed& other);
        int    operator>(const Fixed& other);
        int    operator<(const Fixed& other);
        int    operator>=(const Fixed& other);
        int    operator<=(const Fixed& other);
        int    operator==(const Fixed& other);
        int    operator!=(const Fixed& other);
        Fixed   operator++( int );
        Fixed   operator--( int );
        Fixed   operator++( void );
        Fixed   operator--( void );
        static Fixed&       min(Fixed& a, Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
    private:
        int value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);