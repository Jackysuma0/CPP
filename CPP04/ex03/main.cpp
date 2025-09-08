#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

// int main() {
// 	IMateriaSource	*src = new MateriaSource();
// 	AMateria		*tmp;
// 	ICharacter		*bob = new Character("Bob");

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	tmp = src->createMateria("ice");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	bob->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	bob->equip(tmp);

// 	bob->use(0, *bob);
// 	bob->use(1, *bob);
// 	bob->use(2, *bob);
// 	bob->use(3, *bob);

// 	AMateria* dropped = bob->getInventorySlot(1);
//     bob->unequip(1);
//     delete dropped; 
	
// 	bob->use(0, *bob);
// 	bob->use(1, *bob);
// 	bob->use(2, *bob);

// 	src->getMemory();

// 	delete src;
// 	delete bob;
// 	return 0;
// }

int main() {
    IMateriaSource *src = new MateriaSource();
    AMateria *tmp;
    ICharacter *bob = new Character("Bob");

    // Learn materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "=== Trying to learn more than 4 materias ===" << std::endl;
    src->learnMateria(new Ice()); // Should be ignored or rejected

    std::cout << "\n=== Equipping materias ===" << std::endl;
    tmp = src->createMateria("ice");
    bob->equip(tmp);
    tmp = src->createMateria("cure");
    bob->equip(tmp);
    tmp = src->createMateria("ice");
    bob->equip(tmp);
    tmp = src->createMateria("cure");
    bob->equip(tmp);

    std::cout << "\n=== Attempting to equip when inventory is full ===" << std::endl;
    tmp = src->createMateria("ice");  // New Ice
    bob->equip(tmp);                   // Should delete tmp, print error

    std::cout << "\n=== Using materias in slots 0 to 3 ===" << std::endl;
    for (int i = 0; i < 4; ++i)
        bob->use(i, *bob);

    std::cout << "\n=== Using invalid slots ===" << std::endl;
    bob->use(-1, *bob); // invalid negative index
    bob->use(4, *bob);  // invalid too high

    std::cout << "\n=== Creating unknown materia ===" << std::endl;
    tmp = src->createMateria("fire");  // Unknown materia, should be nullptr
    if (tmp == NULL)
        std::cout << "createMateria(\"fire\") returned nullptr as expected." << std::endl;
    else
        std::cout << "Unexpected materia created!" << std::endl;

    std::cout << "\n=== Unequipping slot 1 and deleting dropped materia ===" << std::endl;
    AMateria* dropped = bob->getInventorySlot(1);
    bob->unequip(1);
    delete dropped;

    std::cout << "\n=== Using slots after unequip ===" << std::endl;
    for (int i = 0; i < 4; ++i)
        bob->use(i, *bob);

    std::cout << "\n=== Trying to unequip invalid slots ===" << std::endl;
    bob->unequip(-1);
    bob->unequip(4);
    bob->unequip(1);  // already empty

    std::cout << "\n=== Re-equipping a new materia in slot 1 ===" << std::endl;
    tmp = src->createMateria("cure");
    bob->equip(tmp);
    bob->use(1, *bob);

    std::cout << "\n=== Final cleanup ===" << std::endl;
    src->getMemory();

    delete src;
    delete bob;

    return 0;
}