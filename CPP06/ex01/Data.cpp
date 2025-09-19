#include "Data.hpp"

Data::Data() : _data("Default")
{
    std::cout << "Default constructor." << std::endl;
}

Data::~Data()
{
    std::cout << "Default deconstructor." << std::endl;
}

Data::Data( const Data& other )
{
    *this = other;
}

Data::Data( std::string data ) : _data(data)
{
    std::cout << "Default constructor with data." << std::endl;
}

Data& Data::operator=( const Data& other )
{
    this->_data = other._data;
    return (*this);
}

std::string Data::getData() const
{
    return(_data);
}