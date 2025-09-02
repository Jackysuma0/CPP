#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default constructor for ScavTrap: " << this->name << " called" << "\n";
}

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default constructor for ScavTrap: " << this->name << " called" << "\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap" << this->name << " has been destroyed" << "\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "Copy constructor for ScavTrap called" << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Copy assignment operator for ScavTrap called" << "\n";
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void    ScavTrap::attack( const std::string& target)
{
    if (this->hitPoints <= 0)
        std::cout << "ScavTrap" << this->name << "Is dead and cannot attack!" << "\n";
    else if (this->energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << "\n";
        this->energyPoints -= 1;
    }
    else
        std::cout << "Not enough energy points!" << "\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap protects itself!" << "\n";
}