#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Default"), _idxTotal(0)
{
    std::cout << "Default constructor for Character was called." << std::endl;
}

Character::Character( std::string name ) : _name(name), _idxTotal(0)
{
    std::cout << "Default constructor for Character named "<< this->_name << " was called." << std::endl;
    int idx;

    idx = 0;
    while (idx < 4)
    {
        this->_inventory[idx] = NULL;
        idx++;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    std::cout << "Default deconstructor for Character named "<< this->_name << " was called." << std::endl;
}

// ICharacter::~ICharacter()
// {
//     std::cout << "ICharacter default destructor was called." << std::endl;
// }

AMateria* Character::getInventorySlot(int idx) const
{
    if (idx < 0 || idx >= 4)
        return NULL;
    return _inventory[idx];
}

Character::Character( Character const &other )
{
    std::cout << "Copy constructor for Character called." << std::endl;
    *this = other;
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        this->_idxTotal = other._idxTotal;
        this->_name = other._name;

        for (int idx = 0; idx < 4; idx++)
        {
            if (other._inventory[idx])
                _inventory[idx] = other._inventory[idx]->clone();
            else
                _inventory[idx] = NULL;
        }
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    if (this->_idxTotal == 4)
    {
        std::cout << this->_name << ": Inventory full! Please unequip a Materia to equip: " << m->getType() << std::endl;
        delete m;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            this->_idxTotal++;
            std::cout << this->_name << " successfully equipped AMateria " << m->getType() << " at idx: " << i << "." << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << this->_name << "'s inventory is empty ! Equip an AMateria to unequip one." << std::endl;
        return ;
    }
    _inventory[idx] = NULL;
    this->_idxTotal--;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << "Nothing in slot " << idx << " of " << this->_name << "'s inventory." << std::endl;
        return;
    }

    _inventory[idx]->use(target);
}