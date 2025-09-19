#include <iostream>
# include <cstdlib>

class Converter
{
    private:
        char	_c;
		int		_i;
		float	_f;
		double	_d;

		bool	_ifPos;
		bool	_ifNeg;
		bool	_nan;
		bool	_err;
    public:
        Converter();
        ~Converter();
        Converter ( std::string& type );
        Converter( const Converter& other );
        Converter& operator=( const Converter& other );

        void    convChar( std::string& type );
        void    convInt( std::string& type );
        void    convFloat( std::string& type );
        void    convDouble( std::string& type );

        void		putChar( void ) const;
		void		putInt( void ) const;
		void		putFloat( void ) const;
		void		putDouble( void ) const;

        void		printer( void ) const;
};