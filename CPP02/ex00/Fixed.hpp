#include <iostream>

class   Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        int    getRawBits( void );
        void    setRawBits( int const raw);
    private:
        int value;
        static const int bits = 8;
};