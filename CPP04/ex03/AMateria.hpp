#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string.h>
#include "Character.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        virtual ~AMateria();
        // AMateria( const std::string type );
        AMateria(const AMateria &other);
        AMateria& operator=(const AMateria &other);
        AMateria(std::string const & type);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif