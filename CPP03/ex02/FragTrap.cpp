#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default constructor for FragTrap: " << this->name << " called" << "\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap" << this->name << " has been destroyed" << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Copy constructor for FragTrap called" << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Copy assignment operator for FragTrap called" << "\n";
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void    FragTrap::highFivesGuys()
{
    std::cout << this->name << " : High five !" << "\n";
}