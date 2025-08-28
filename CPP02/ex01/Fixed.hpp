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
        int    getRawBits( void );
        void    setRawBits( int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
    private:
        int value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);