#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	////////////////////////////////////////
	//									  //
	//			Form exceptions			  //
	//									  //
	////////////////////////////////////////

	try
	{
		Form	Form( "A123", 0, 1 );
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	Form( "A123", 1, 0 );
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	Form( "A123", 1, 151 );
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	Form( "A123", 151, 1 );
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	
	////////////////////////////////////////
	//									  //
	//	      Form and Bureaucrat	      //
	//									  //
	////////////////////////////////////////

	try
	{
		Bureaucrat	Simon = Bureaucrat( "Simon", 1 );
		Form		Form( "A123", 150, 150 );

		std::cout << Form << std::endl;
		Simon.signForm( Form );
		std::cout << Form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	
	try
	{
		Bureaucrat	Simon = Bureaucrat( "Simon", 10 );
		Form		Form( "A123", 1, 1 );

		std::cout << Form << std::endl;
		Simon.signForm( Form );
		std::cout << Form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}