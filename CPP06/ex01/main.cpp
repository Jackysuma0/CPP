#include "Data.hpp"

int main( void )
{

    Data        data("Hello");
    uintptr_t   p;
    
    std::cout << "address: " << &data << ", of value: " << data.getData() << std::endl;
    p = serialize( ( Data* ) &data );

    std::cout << "serialized: " << p << std::endl;
    std::cout << "deserialize: " << deserialize( p ) << ", of value: " << deserialize( p )->getData() << std::endl;

}