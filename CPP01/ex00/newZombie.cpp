#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << this->name << " has been created." << "\n";
    return;
}

Zombie::~Zombie()
{
    std::cout << name << " has been deleted." << "\n";
    return;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << this->name << " has been created." << std::endl;
}

Zombie* newZombie( std::string name )
{
    return(new Zombie(name));//example of stack
}
