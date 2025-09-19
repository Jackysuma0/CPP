#include <vector>
#include "easyfind.hpp"

int main( void ) {

    std::vector<int>    vec;
    int                 i = 0;
    
    while ( i < 5 ) {
    
        vec.push_back( i );
        i++;
    }
    try
    {
        easyfind( vec, 2 );
        std::cout << "You should see me" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        easyfind( vec, 9 );
        std::cout << "You should not see me" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}