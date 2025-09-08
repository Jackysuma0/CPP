#include "Brain.hpp"

Brain::Brain()
{
    // this->type = getType();
    std::cout << "Brain chose you as his new owner." << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain decided to leave this place!" << std::endl; 
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor for Brain called." << "\n";
    *this = other;
}

Brain& Brain::operator=(const Brain &other)
{
    int i;

    i = 0;
    std::cout << "Copy assignment operator for Brain called." << "\n";
    if ( this == &other )
        return (*this);
    while (i < 100)
    {
        this->_ideas[i] = other._ideas[i];
        i++;
    }
    return ( *this );
}

void    Brain::setIdeas( const std::string ideas, int pos )
{
    int i;

    i = 0;
    if ( pos > 100 )
        std::cout << "Too much ideas, brain is too small for this." << std::endl;
    else
    {
        while ( i < pos )
        {
            i++;
        }
        _ideas[i] = ideas;
    }
}

std::string Brain::getIdeas( int pos ) const
{
    int i;

    i = 0;
    if ( pos > 100 )
        std::cout << "Too much ideas, brain is too small for this." << std::endl;
    else
    {
        while ( i < pos )
            i++;
        return (_ideas[i]);
    }
    return ( NULL );
}