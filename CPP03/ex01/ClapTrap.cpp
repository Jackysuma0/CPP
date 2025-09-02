#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "Default constructor for ClapTrap: " << this->name << " called" << "\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " ClapTrap has been destroyed" << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor for ClapTrap called" << "\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator for ClapTrap called" << "\n";
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
    if (this->hitPoints == 0)
        std::cout << "ClapTrap" << this->name << "Not enough hit points!" << "\n";
    else if (this->energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << "\n";
        this->energyPoints -= 1;
    }
    else
        std::cout << "Not enough energy points!" << "\n";

}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == 0)
        std::cout << "This action does nothing." << "\n";
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap" << this->name << "is already dead" << "\n";
    else if (this->energyPoints <= 0)
        std::cout << "Not enough energy points!" << "\n";
    else
    {
        std::cout << this->name << " Took damage equal to: " << amount << "\n";
        this->hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount == 0)
        std::cout << "This action does nothing." << "\n";
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap" << this->name << "is already dead and can't be fixed" << "\n";
    else if (this->energyPoints <= 0)
        std::cout << "Not enough energy points!" << "\n";
    else
    {
        std::cout << this->name << " Repaired himself: " << amount << " health" << "\n";
        this->hitPoints += amount;
    }
}
