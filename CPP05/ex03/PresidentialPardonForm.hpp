#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class   PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm( const PresidentialPardonForm& );
        PresidentialPardonForm&     operator=( const PresidentialPardonForm& );
        void                        execute( const Bureaucrat& ) const ;
        PresidentialPardonForm( const std::string );
        PresidentialPardonForm();
        ~PresidentialPardonForm( void );
    private:
};

#endif