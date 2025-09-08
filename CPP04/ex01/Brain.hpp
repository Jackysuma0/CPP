#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain& operator=( const Brain &other);
        Brain( const Brain &other);
        std::string     getIdeas( int ) const;
        void            setIdeas( const std::string, int );
};

#endif