#include "AForm.hpp"

AForm::AForm() : _name("Default"), _grade_execute(1), _grade_required(1), _signed(0)
{
    std::cout << "Default constructor for AForm has been called" << std::endl;
}

AForm::AForm( const std::string name, int grade, int grade_req ) : _name(name), _grade_execute(grade), _grade_required(grade_req), _signed(0)
{
    std::cout << "Name constructor for AForm named: " << this->_name << " has been called." << std::endl;
    if (grade < 1 || grade_req < 1)
        throw AForm::GradeTooLowException();
    if (grade > 150 || grade_req > 150)
        throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
    std::cout << "Default deconstructor for AForm has been called." << std::endl;
}

AForm::AForm( const AForm &other) : _grade_execute(1), _grade_required(1)
{
    *this = other;
}

AForm& AForm::operator=(const AForm &other)
{
    if ( this == &other )
        return ( *this );
    
    std::string *stringPTR = ( std::string* )&this->_name;
    int   *signGrade = ( int* )&this->_grade_required;
    int   *execGrade = ( int* )&this->_grade_execute;

    *stringPTR = other._name;
    *signGrade = other._grade_required;
    *execGrade = other._grade_execute;
    return ( *this );
}

std::string AForm::getName() const
{
    return (_name);
}

bool    AForm::isSigned()
{
    return (_signed);
}

int AForm::getGradeRequired()
{
    return (_grade_required);
}

int AForm::getGradeExecuted()
{
    return (_grade_execute);
}

void    AForm::beSigned( Bureaucrat& which )
{
    if (which.getGrade() > _grade_required)
        throw GradeTooLowException();
    else
        this->_signed = 1;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("Grade is too High ! ");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("Grade is too low ! ");
}

std::ostream&   operator<<( std::ostream& stream, AForm& AForm )
{
    stream << "AForm's name is : " << AForm.getName() << ", is signed : " << AForm.isSigned() << ", grade to sign : " << AForm.getGradeRequired() << ", grade to exec :" << AForm.getGradeExecuted() << "." << std::endl;
    return ( stream );
}