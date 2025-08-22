#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << this->name << "Zombie is alive." << "\n";
    return;
}

Zombie::~Zombie()
{
    std::cout << "Zombie got deleted." << "\n";
    return;
}

// Zombie::Zombie(std::string name)
// {
//     this->name = name;
//     std::cout << this->name << " has been created." << std::endl;
// }

void Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
