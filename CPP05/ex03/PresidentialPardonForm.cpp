#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
    std::cout << "Default constructor for PresidentialPardonForm has been called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string name ) : AForm(name, 25, 5)
{
    std::cout << "Name constructor for PresidentialPardonForm has been called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other)
{
    std::cout << "PresidentialPardonForm's copy constructor called" << std::endl;
    // *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm's copy deconstructor called" << std::endl;
}

void    PresidentialPardonForm::execute( const Bureaucrat& exec) const
{

    if ( exec.getGrade() > getGradeRequired() )
        throw AForm::GradeTooLowException();
    else
        std::cout << exec.getName() << " has been forgiven by President Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& ref ) {

    if ( this == &ref )
        return ( *this );
    AForm::operator=( ref );
    return ( *this );
}