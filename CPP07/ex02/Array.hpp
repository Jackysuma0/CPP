#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T*  _array;
        size_t  _size;
    public:
        Array() : _array( NULL ), _size( 0 ) { };
        Array( unsigned int n ) : _array( new T[n] ), _size( n ) { };
        Array( const Array& other ) { *this = other; };
        ~Array() { delete[]( _array ); };
        Array& operator=( const Array& other )
        {
            size_t  i = 0;
            _size = other._size;
            _array = new T[_size];
            while (i < _size )
            {
                _array[i] = other._array[i];
                i++;
            }
            return ( *this );
        }
        T& operator[]( int i )
        {
            if ( i > -1 && static_cast<unsigned int>( i ) < _size )
                return (_array[i]);
            else
                throw invalidIndex(); 
        }
        size_t  size() const { return( _size ); };
        class invalidIndex : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("Invalid index"); };
        };
};