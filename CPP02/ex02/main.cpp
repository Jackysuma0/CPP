#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}


// int main() {
//     Fixed a;                     // Default constructor
//     Fixed b(5);                  // Int constructor
//     Fixed c(3.14f);              // Float constructor
//     Fixed d(b);                  // Copy constructor

//     std::cout << "\n--- Operator << and Conversions ---\n";
//     std::cout << "a = " << a << "\n";
//     std::cout << "b = " << b << " | toInt: " << b.toInt() << "\n";
//     std::cout << "c = " << c << " | toFloat: " << c.toFloat() << "\n";
//     std::cout << "d = " << d << "\n";

//     std::cout << "\n--- Comparison Operators ---\n";
//     std::cout << "b > c : " << (b > c) << "\n";
//     std::cout << "b < c : " << (b < c) << "\n";
//     std::cout << "b >= d : " << (b >= d) << "\n";
//     std::cout << "b <= d : " << (b <= d) << "\n";
//     std::cout << "b == d : " << (b == d) << "\n";
//     std::cout << "b != c : " << (b != c) << "\n";

//     std::cout << "\n--- Arithmetic Operators ---\n";
//     Fixed sum = b + c;
//     Fixed diff = b - c;
//     Fixed prod = b * c;
//     Fixed div = b / c;
//     std::cout << "b + c = " << sum << "\n";
//     std::cout << "b - c = " << diff << "\n";
//     std::cout << "b * c = " << prod << "\n";
//     std::cout << "b / c = " << div << "\n";

//     std::cout << "\n--- Increment / Decrement ---\n";
//     Fixed e;
//     std::cout << "e = " << e << "\n";
//     std::cout << "++e = " << ++e << "\n"; // Pre-increment
//     std::cout << "e = " << e << "\n";
//     std::cout << "e++ = " << e++ << "\n"; // Post-increment
//     std::cout << "e = " << e << "\n";
//     std::cout << "--e = " << --e << "\n"; // Pre-decrement
//     std::cout << "e = " << e << "\n";
//     std::cout << "e-- = " << e-- << "\n"; // Post-decrement
//     std::cout << "e = " << e << "\n";

//     std::cout << "\n--- Min / Max ---\n";
//     std::cout << "min(b, c) = " << Fixed::min(b, c) << "\n";
//     std::cout << "max(b, c) = " << Fixed::max(b, c) << "\n";
//     const Fixed cf1(10.5f);
//     const Fixed cf2(10.6f);
//     std::cout << "const min = " << Fixed::min(cf1, cf2) << "\n";
//     std::cout << "const max = " << Fixed::max(cf1, cf2) << "\n";

//     std::cout << "\n--- Assignment Operator ---\n";
//     Fixed f;
//     f = c;
//     std::cout << "f = " << f << " (after f = c)\n";

//     return 0;
// }