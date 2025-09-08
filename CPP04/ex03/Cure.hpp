#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
// #include "Character.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure( const Cure &other );
        ~Cure();
        Cure& operator=( Cure const &other );
        virtual AMateria *clone() const;
        virtual void    use( ICharacter &target );
};

#endif