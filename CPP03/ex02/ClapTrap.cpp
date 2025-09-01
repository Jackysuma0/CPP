#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default constructor for: " << this->name << " called" << "\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " has been destroyed" << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << "\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << "\n";
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

void    ClapTrap::attack( const std::string& target)
{
    if (this->energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << "\n";
        this->energyPoints -= 1;
    }
    else
        std::cout << "Not enough hit points!" << "\n";

}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name << " Took damage equal to: " << amount << "\n";
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->name << " Repaired himself: " << amount << " health" << "\n";
    this->hitPoints += amount;
}
