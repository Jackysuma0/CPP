#include "Converter.hpp"

int main( int argc, char** argv )
{

    std::string	arg;
	Converter*	convert;

    if ( argc != 2 ) {

        std::cout << "Invalid number of arguments! Please write the following : ./convert [value]" << std::endl;
        return ( 130 );        
    }
    else {

		arg = argv[1];
        convert = new Converter( arg );
		convert->printer();

		delete ( convert );
    }
    
    return ( 0 );
}