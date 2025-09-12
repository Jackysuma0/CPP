#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class   ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm( const ShrubberyCreationForm& );
        ShrubberyCreationForm&     operator=( const ShrubberyCreationForm& );
        void                        execute( const Bureaucrat& ) const ;
        ShrubberyCreationForm( const std::string );
        ShrubberyCreationForm();
        ~ShrubberyCreationForm( void );
    private:
};