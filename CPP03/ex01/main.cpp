#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	ScavTrap		*clap = new ScavTrap("SC4V-TP");

	std::cout << std::endl;
    std::cout << " attack on CL4P-TP " << std::endl;
    clap->attack("CL4P-TP");
    std::cout << " attack with no damage " << std::endl;
    clap->takeDamage( 0 );
    std::cout << " repair of 1 point " << std::endl;
    clap->beRepaired( 1 );
    std::cout << " repair of 0 point " << std::endl;
    clap->beRepaired( 0 );
    std::cout << " taking 10 damage points " << std::endl;
    clap->takeDamage( 10 );
	std::cout << std::endl << std::endl;
    std::cout << " testing the energy" << std::endl;
    for (int i = 0; i < 48; i++) {
        
        clap->beRepaired( 1 );        
    }
	std::cout << std::endl << std::endl;
    std::cout << " taking 139 damage points " << std::endl;
    clap->takeDamage( 139 );
    std::cout << " taking 1 damage point " << std::endl;
    clap->takeDamage( 1 );
    std::cout << " repair of 1 point " << std::endl;
	clap->beRepaired( 1 );
    std::cout << std::endl;
    
    clap->guardGate();
    std::cout << std::endl;
	delete clap;

	return (0);
}