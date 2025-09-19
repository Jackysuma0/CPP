#include "Converter.hpp"

Converter::Converter() : _c(0), _i(0), _f(0), _d(0)
{
    // std::cout << "Default constructor has been called." << std::endl;
}

Converter::~Converter()
{
    // std::cout << "Default deconstructor has been called." << std::endl;
}

Converter::Converter( const Converter& other )
{
    *this = other;
}

Converter& Converter::operator=( const Converter& other )
{
    _c = other._c;
    _i = other._i;
    _f = other._f;
    _d = other._d;

    _ifPos = other._ifPos;
    _ifNeg = other._ifNeg;
    _nan = other._nan;
    _err = other._err;
	return ( *this );
}

void    Converter::convChar( std::string& type )
{
    _c = type[0];
    _i = static_cast <int>( _c );
    _f = static_cast <float>( _c );
    _d = static_cast <double>( _c );
}

void    Converter::putChar() const
{
    if (_ifNeg == 1 || _ifPos == 1 || _nan == 1 || _err == 1)
        std::cout << "Impossible" << std::endl;
    else if (std::isprint(_c) == 0)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "\'" << _c << "\'" << std::endl;
}

void    Converter::convInt( std::string& type )
{
    _i = atoi(type.c_str());
    _c = static_cast <char>( _i );
    _f = static_cast <float>( _i );
    _d = static_cast <double> ( _i );
}

void    Converter::putInt() const
{
    if (_ifNeg == 1 || _ifPos == 1 || _nan == 1 || _err == 1)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << _i << std::endl;
}

void    Converter::convFloat( std::string& type )
{
    _f = atof(type.c_str());
    _c = static_cast <char>( _f );
    _i = static_cast <int>( _f );
    _d = static_cast <double>( _f );
}

void    Converter::putFloat() const
{
    if (_ifNeg == 1)
        std::cout << "-inff" << std::endl;
    else if (_ifPos == 1)
        std::cout << "+inff" << std::endl;
    else if(_nan == 1)
        std::cout << "nanf" << std::endl;
    else if (_err == 1)
        std::cout << "Impossible" << std::endl;
    else
    {
        if (_f != static_cast <int>( _f ))
            std::cout << _f << "f" << std::endl;
        else
            std::cout << _f << ".0f" << std::endl;
    }
}

void    Converter::convDouble( std::string& type )
{
    _d = atof(type.c_str());
    _c = static_cast <char>( _d );
    _i = static_cast <int>( _d );
    _f = static_cast <float>( _d );
}

void    Converter::putDouble() const
{
    if (_ifNeg == 1)
        std::cout << "-inff" << std::endl;
    else if (_ifPos == 1)
        std::cout << "+inff" << std::endl;
    else if(_nan == 1)
        std::cout << "nan" << std::endl;
    else if (_err == 1)
        std::cout << "Impossible" << std::endl;
    else
    {
        if (_d != static_cast <int>( _f ))
            std::cout << _d << std::endl;
        else
            std::cout << _d << ".0" << std::endl;
    }
}

int rightChars(const std::string& arg) {
	for (size_t i = 0; i < arg.length(); ++i) {
		char c = arg[i];
		if ((c < '0' || c > '9') && c != 'f' && c != '-' && c != '.')
			return 0;
	}
	return 1;
}

int withinLim(const std::string& arg) {
	long val = atol(arg.c_str());
	if (val > 2147483647L || val < -2147483648L)
		return 0;
	return 1;
}

bool	isChar( std::string& type )
{

	if ( type.length() == 1 && type[0] == 0 )
		return ( 0 ); 
	if ( type.length() == 1 && std::isprint(type[0]))
		return ( 1 );
	return ( 0 );
}

bool    isInt( std::string& type )
{

    size_t	i;

	i = 0;
	while ( i < type.length() ) {
	
		if ( i == 0 && ( type[i] < '0' || type[i] > '9' ) && type[i] != '-' )
			return ( 0 );
		if ( i > 0 && ( type[i] < '0' || type[i] > '9' ) )
			return ( 0 );
		i++;
	}
	return ( 1 );
}

bool	isFloat( std::string& type )
{

	if ( type[type.length() - 1 ] == 'f')
		return ( 1 );
	return ( 0 );
}

bool	isDouble( std::string& type )
{

	if ( type.find('.') )
		return ( 1 );
	return ( 0 );
}

Converter::Converter( std::string& arg ) :_ifPos( 0 ), _ifNeg( 0 ), _nan( 0 ), _err( 0 )
{
	
	if ( arg.compare( "+inf" ) == 0 || arg.compare( "+inff" ) == 0 )
		_ifPos = 1;
	else if ( arg.compare( "-inf" ) == 0 || arg.compare( "-inff" ) == 0 )
		_ifNeg = 1;
	else if ( arg.compare( "nan" ) == 0 || arg.compare( "nanf" ) == 0 )
		_nan = 1;
	else if ( ( arg.length() > 1 && rightChars( arg ) == 0 ) || withinLim( arg ) == 0 )
		_err = 1;
    else if ( isChar( arg ) )
        convChar( arg );
	else if ( isInt( arg ) )
		convInt( arg );
	else if ( isFloat( arg ) )
		convFloat( arg );
	else if ( isDouble( arg ) )
		convDouble( arg );
	else
		_err = 1;
}

void	Converter::printer( void ) const
{

	std::cout << "char: ";
	this->putChar();
	std::cout << "int: ";
	this->putInt();
	std::cout << "float: ";
	this->putFloat();
	std::cout << "double: ";
	this->putDouble();
}