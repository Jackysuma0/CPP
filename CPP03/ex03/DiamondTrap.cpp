#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "Default constructor for DiamondTrap: " << this->name << " called" << "\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap" << this->name << " has been destroyed" << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "Copy constructor for DiamondTrap called" << "\n";
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "Copy assignment operator for DiamondTrap called" << "\n";
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "I'm " << this->name << ", and here's my ClapTrap's name " << ClapTrap::name << "." << std::endl;
}