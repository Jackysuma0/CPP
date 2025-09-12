#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
    std::cout << "Default constructor for RobotomyRequestForm has been called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string name ) : AForm(name, 72, 45)
{
    std::cout << "Name constructor for RobotomyRequestForm has been called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
{
    std::cout << "RobotomyRequestForm's copy constructor called" << std::endl;
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm's copy deconstructor called" << std::endl;
}

void    RobotomyRequestForm::execute( const Bureaucrat& exec) const
{
    int i;

    if ( exec.getGrade() > getGradeRequired() )
        throw AForm::GradeTooLowException();
    else
    {
        std::srand( time( NULL ) );
        i = std::rand() % 2;
        std::cout << "BRRRRRRRRRRRRR" << std::endl;
        if ( i == 0 )
            std::cout << exec.getName() << " had been robotomized with 50\% of success!" << std::endl;
        else
            std::cout << "The robotization of " << exec.getName() << " had failed!" << std::endl;
    }
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& ref ) {

    if ( this == &ref )
        return ( *this );
    AForm::operator=( ref );
    return ( *this );
}