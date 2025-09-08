#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
// #include "Character.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( const Ice &other );
        ~Ice();
        Ice& operator=( Ice const &other );
        virtual AMateria *clone() const;
        virtual void    use( ICharacter &target );
};

#endif