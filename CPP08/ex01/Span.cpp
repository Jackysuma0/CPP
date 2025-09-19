#include "Span.hpp"

Span::Span() : _size( 0 ), _vec( ) { }

Span::Span( size_t i ) : _size( i ),  _vec( ) { }

Span::Span( const Span& other )
{
    *this = other;
}

Span::~Span() { }

Span&   Span::operator=(const Span& other )
{
    if ( this == &other ) {
        
        return ( *this );
    }
    _size = other._size;
    return( *this );
}

void    Span::addNumber( size_t i )
{
    if (_vec.size() >= _size )
        throw( Span::tooMuch() );
    _vec.push_back( i );
}

size_t Span::longestSpan()
{
    if (_vec.size() < 2)
        throw( Span::noNumber() );
    int minVal = *std::min_element(_vec.begin(), _vec.end() );
    int maxVal = *std::max_element(_vec.begin(), _vec.end() );
    return (maxVal - minVal);
}

size_t  Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw( Span::noNumber() );
    std::vector<int> sorted = _vec;
    std::sort(_vec.begin(), _vec.end());
    int shortest = std::numeric_limits<int>::max();
    size_t i = 1;
    int dif;
    while( i < sorted.size() )
    {
        dif = _vec[i] - _vec[i - 1];
        if (dif < shortest)
            shortest = dif;
        i++;
    }
    return (static_cast<size_t>(shortest));
}

void    Span::displayVec( void ) {

    std::vector<int>::iterator it1 = _vec.begin();
	std::vector<int>::iterator it2 = _vec.end();
    while(it1 != it2)
        std::cout << *it1++ << std::endl;
}

void    Span::addIter( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {

    if ( std::distance( begin, end ) + _vec.size() >= _size )
        throw ( Span::tooMuchRange() );
    _vec.insert( _vec.end(), begin, end );
}