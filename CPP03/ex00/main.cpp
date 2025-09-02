#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap		*clap = new ClapTrap("P. ClapTrappington");
    
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
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
    clap->beRepaired( 1 );
	std::cout << std::endl << std::endl;
    std::cout << " taking 10 damage points " << std::endl;
    clap->takeDamage( 9 );
    std::cout << " taking 1 damage point " << std::endl;
    clap->takeDamage( 1 );
    std::cout << " repair of 1 point " << std::endl;
	clap->beRepaired( 1 );
    
    std::cout << std::endl;
    
	delete clap;

	return (0);
}