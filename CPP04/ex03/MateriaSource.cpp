#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idxTotal(0)
{
    int i;

    i = 0;
    while (i < 4)
    {
        _memory[i] = NULL;
        i++;
    }
	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const &other )
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_memory[i])
            delete _memory[i];
    }
    std::cout << "MateriaSource destructor called." << std::endl;
}

// IMateriaSource::~IMateriaSource()
// {
// 	std::cout << "IMateriaSource interface default destructor called." << std::endl;
// }

MateriaSource &	MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "MateriaSource assignment operator called." << std::endl;
    if (this != &other)
    {
        _idxTotal = other._idxTotal;
        for (int i = 0; i < 4; ++i)
        {
            if (_memory[i])
                delete _memory[i];
            if (other._memory[i])
                _memory[i] = other._memory[i]->clone();
            else
                _memory[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::getMemory() const
{
    for (int i = 0; i < _idxTotal; i++)
    {
        if (_memory[i])
            std::cout << "Materia stored: " << _memory[i]->getType() << std::endl;
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return;

    if (_idxTotal >= 4)
    {
        std::cout << "MateriaSource is full, can't learn more Materias." << std::endl;
        delete materia;
        return;
    }

    _memory[_idxTotal++] = materia;
    std::cout << "MateriaSource learned a new Materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_memory[i] && _memory[i]->getType() == type)
        {
            std::cout << "MateriaSource created a Materia of type: " << type << std::endl;
            return _memory[i]->clone();
        }
    }
    std::cout << "MateriaSource could not find Materia of type: " << type << std::endl;
    return NULL;
}