#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Span
{
    private:
        size_t  _size;
        std::vector<int> _vec;
    public:
        Span();
        Span( size_t i );
        Span( const Span& other );
        ~Span();
        Span& operator=( const Span& other );
        void addNumber( size_t i );
        void    displayVec( void );
        void    addIter( std::vector<int>::iterator, std::vector<int>::iterator );
        size_t  shortestSpan( );
        size_t  longestSpan( );
    class tooMuchRange : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("The range you're trying to add is too big");
            }
    };
    class noNumber : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("No number in vector");
            }
    };
    class tooMuch : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Vector full");
            }
    };
};