#include "Zombie.hpp"

int main()
{
    Zombie* new_zombie = newZombie("Foo");
    new_zombie->announce();
    delete(new_zombie);

    randomChump("Bar");
    return (0);
}