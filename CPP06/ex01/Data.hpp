#include <iostream>
#include <stdint.h>

class Data
{
    private:
        std::string _data;
    public:
        Data();
        ~Data();
        Data( std::string data );
        Data( const Data& other );
        Data& operator=( const Data& other );
        std::string getData() const;
};

uintptr_t serialize( Data* p );
Data*   deserialize( uintptr_t r );