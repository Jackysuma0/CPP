#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    Hero("Hero");
    ClapTrap*   Evil = new ClapTrap("Evil");
    ScavTrap    Dragon("Dragon");
    FragTrap    Slayer("Slayer");

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
    Slayer.attack("Dragon");
    Dragon.takeDamage(20);

    std::cout << "\nSlayer requests a high five\n";
    Slayer.highFivesGuys();

    delete Evil;

    std::cout << "\nEnd of main — destructors will be called now\n";
    return 0;
}