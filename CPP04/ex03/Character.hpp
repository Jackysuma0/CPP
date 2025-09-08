#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string.h>
// #include "AMateria.hpp"

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual AMateria* getInventorySlot( int idx ) const = 0;
};

class Character : public ICharacter
{
    private:
        std::string _name;
        int         _idxTotal;
        AMateria    *_inventory[4];
    public:
        Character( std::string name );
        virtual ~Character();
        Character();
        Character( const Character &other );
        Character &operator=( const Character &other );
        virtual std::string const & getName() const;
        virtual void    equip( AMateria* m );
        virtual void    unequip( int idx );
        virtual void    use( int idx, ICharacter &target );
        virtual AMateria* getInventorySlot( int idx ) const;
};

#endif