#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal   *tabAnimal[10];
    int i;

    i = 0;
    while ( i < 10 ) {
    
        if ( ( i % 2 ) == 0 )
            tabAnimal[i] = new Cat();
        else
            tabAnimal[i] = new Dog();
        i++;
    }
    std::cout << std::endl;
    i = 0;
    while ( i < 10 )
    {
        std::cout << "The " << tabAnimal[i]->getType() << " says ";
        tabAnimal[i++]->makeSound();
    }
    std::cout << std::endl;
    i = 0;
    while ( i < 10 ) {

        delete( tabAnimal[i++] );
	}
    std::cout << std::endl << std::endl;
	Cat	*leChat = new Cat();
    std::cout << std::endl;
	std::string idea0 = "Meow";
	std::string idea1 = "Feed me, tall skinny figure";
	leChat->setIdeas( idea0, 0 );
	leChat->setIdeas( idea1, 1 );
    std::cout << leChat->getIdeas(0) << std::endl;
    std::cout << leChat->getIdeas(1) << std::endl;
    std::cout << std::endl << std::endl;
    delete( leChat );
    std::cout << std::endl << std::endl;
    WrongAnimal *WrongMeow = new WrongCat;
    std::cout << "WrongCat says: ";
    WrongMeow->makeSound();
    std::cout << std::endl << std::endl;
    delete( WrongMeow );
    /////////////ABSTRACT TEST/////////////
    // Animal  *animal = new Animal();
    
    // animal->makeSound();
    return 0;
}