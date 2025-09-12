#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class   RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm( const RobotomyRequestForm& );
        RobotomyRequestForm&     operator=( const RobotomyRequestForm& );
        void                        execute( const Bureaucrat& ) const ;
        RobotomyRequestForm( const std::string );
        RobotomyRequestForm();
        ~RobotomyRequestForm( void );
    private:
};