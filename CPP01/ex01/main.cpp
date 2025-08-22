#include "Zombie.hpp"

int main()
{
    Zombie* horde = zombieHorde(5, "Foo");
    delete[] (horde);
    return (0);
}