#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {

	DiamondTrap		*clap = new DiamondTrap("FR4G-TP");

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
    for ( int i = 0; i < 98; i++ ) {
        
        clap->beRepaired( 1 );
    }
	std::cout << std::endl << std::endl;
    std::cout << " taking 189 damage points " << std::endl;
    clap->takeDamage( 189 );
    std::cout << " taking 1 damage point " << std::endl;
    clap->takeDamage( 1 );
    std::cout << " repair of 1 point " << std::endl;
	clap->beRepaired( 1 );
    std::cout << std::endl;
    
    clap->highFivesGuys();
	clap->attack("CL4P-TP");
	clap->whoAmI();
    
	delete clap;

	return (0);
}