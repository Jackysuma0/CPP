#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
    std::cout << "Default constructor for Bureaucrat has been called." << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
    std::cout << "Name constructor for Bureaucrat named: " << this->_name << " has been called." << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat( const std::string name ) : _name(name)
{
    std::cout << "Name constructor for Bureaucrat has been called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default deconstructor for Bureaucrat has been called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    std::cout << "Copy assignment operator for Bureaucrat called" << "\n";
    if (this == &other)
    {
        return (*this);
    }
    _grade = other._grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::decrementGrade( int i )
{
    if (_grade + i > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade += i;
}

void Bureaucrat::incrementGrade( int i )
{
    if (_grade - i < 1)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade -= i;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high ! ");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low ! ");
}

void    Bureaucrat::signForm( Form& form )
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << "." << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

void    Bureaucrat::executeForm( Form& form )
{
    try
    {
        form.execute(*this);
        std::cout << _name << " signed " << form.getName() << "." << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}