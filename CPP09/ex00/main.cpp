#include "BitcoinExchange.hpp"

int     printErr( std::string str, int i )
{
    std::cerr << str << std::endl;
    return ( i );
}

int     main( int argc, char **argv ) {

    std::fstream    csv;
    std::fstream    entryFile;

    if ( argc != 2 )
        return ( printErr( "Wrong amount of arguments!\n./btc NameOfFile", 1 ) );
    csv.open( "data.csv" );
    try
    {
        csv.exceptions( csv.failbit );
    }
    catch( const std::ios_base::failure& e )
    {
        std::cerr << "Missing initial database, ";
        return ( printErr( e.what(), 2 ) );
    }
    entryFile.open( argv[1] );
    try
    {
        entryFile.exceptions( entryFile.failbit );
    }
    catch( const std::ios_base::failure& e )
    {
        std::cerr << "Can't open file, ";
        return ( printErr( e.what(), 3 ) );
    }
    std::cout << "Pass" << std::endl;
    BitcoinExchange btcx;

    try
    {
        btcx.readFile("data.csv");
        btcx.processData(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return ( 1 );
    }
    
    return ( 0 ); 
}