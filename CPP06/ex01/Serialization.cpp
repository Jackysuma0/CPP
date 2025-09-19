#include "Data.hpp"

uintptr_t serialize( Data *p )
{
    return (reinterpret_cast<uintptr_t>( p ));
}

Data* deserialize( uintptr_t r)
{
    return ( reinterpret_cast<Data*>( r ));
}