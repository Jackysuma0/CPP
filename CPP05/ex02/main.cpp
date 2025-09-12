#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{

	AForm			*form = NULL;
	Bureaucrat		High( "High", 1 );
	Bureaucrat		Mid( "Mid", 75 );
	Bureaucrat		Low( "Low", 150 );
	
	std::cout << std::endl << std::endl;

	try
	{
		form = new PresidentialPardonForm( "A123" );
		form->execute( High );
		delete ( form );
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;

	try
	{
		form = new RobotomyRequestForm( "A123" );
		form->execute( Mid );
		delete ( form );
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	form = NULL;
	
	std::cout << std::endl;

	try
	{
		form = new ShrubberyCreationForm( "A123" );
		form->execute( Low );
		delete ( form );
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;

	High.executeForm( PresidentialPardonForm( "A123" ) );
	Mid.executeForm( PresidentialPardonForm( "A123" ) );
	
	std::cout << std::endl;
	
	High.executeForm( RobotomyRequestForm( "A123" ) );
	Mid.executeForm( RobotomyRequestForm( "A123" ) );

	std::cout << std::endl;

	High.executeForm( ShrubberyCreationForm( "A123" ) );

	delete form;
	return ( 0 );	
}