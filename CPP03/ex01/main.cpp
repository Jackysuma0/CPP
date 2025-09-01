#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap    Hero("Hero");
    ClapTrap*   Evil = new ClapTrap("Evil");
    ScavTrap    Dragon("Dragon");

    std::cout << "\nHero attacks Dragon\n";
    Hero.attack("Dragon");
    Dragon.takeDamage(5);
    std::cout << "\nDragon repairs himself\n";
    Dragon.beRepaired(15);
    std::cout << "\nDragon enters Guard Gate mode\n";
    Dragon.guardGate();
    std::cout << "\nDragon attacks Evil\n";
    Dragon.attack("Evil");
    Evil->takeDamage(10);
    std::cout << "\nSlayer attacks Dragon\n";
    Dragon.takeDamage(20);
    std::cout << "\nSlayer requests a high five\n";
    delete Evil;
    std::cout << "\nEnd of main — destructors will be called now\n";
    return 0;
}