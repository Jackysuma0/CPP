#include "ClapTrap.hpp"

int main()
{
    ClapTrap    Hero("Hero");
    ClapTrap    Evil("Evil");

    Hero.attack("Evil");
    Evil.takeDamage(10);
    Hero.beRepaired(1);
    return (0);
}