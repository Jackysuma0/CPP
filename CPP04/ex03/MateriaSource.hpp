#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string.h>
#include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void	getMemory() const = 0;
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        int _idxTotal;
        AMateria* _memory[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource( MateriaSource const &other );
        MateriaSource& operator=( MateriaSource const &other );
        virtual void	getMemory() const;
        virtual void	learnMateria( AMateria *materia );
		virtual AMateria *	createMateria( std::string const &type );
};

#endif