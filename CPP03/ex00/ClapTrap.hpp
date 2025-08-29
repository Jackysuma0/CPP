#include <iostream>
#include <string>

class ClapTrap
{
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
    private:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         attackDamage;
};