#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void ) {

	AForm* A1;
	AForm* A2;
	AForm* A3;
	AForm* A4;
	Intern someRandomIntern;

	std::cout << std::endl << std::endl;
	
	A1 = someRandomIntern.makeForm("presidential pardon", "Obama Prism");

	std::cout << std::endl << std::endl;
	
	A2 = someRandomIntern.makeForm("robotomy request", "Bender");
	
	std::cout << std::endl << std::endl;
	
	A3 = someRandomIntern.makeForm("shrubbery creation", "Tree");
	
	std::cout << std::endl << std::endl;
	
	A4 = someRandomIntern.makeForm("Jacques", "Jacques");

	std::cout << std::endl << std::endl;

	delete ( A1 );
	delete ( A2 );
	delete ( A3 );
	delete( A4 );
	return ( 0 );
}