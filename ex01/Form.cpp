#include "Form.hpp"

Form::Form() : _name("Default"), _grade_execute(1), _grade_required(1), _signed(0)
{
    std::cout << "Default constructor for Form has been called" << std::endl;
}

Form::Form( const std::string name, int grade, int grade_req ) : _name(name), _grade_execute(grade), _grade_required(grade_req), _signed(0)
{
    std::cout << "Name constructor for Form named: " << this->_name << " has been called." << std::endl;
    if (grade < 1 || grade_req < 1)
        throw Form::GradeTooLowException();
    if (grade > 150 || grade_req > 150)
        throw Form::GradeTooHighException();
}

Form::~Form()
{
    std::cout << "Default deconstructor for Form has been called." << std::endl;
}

Form::Form( const Form &other) : _grade_execute(1), _grade_required(1)
{
    *this = other;
}

Form& Form::operator=(const Form &other)
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

std::string Form::getName() const
{
    return (_name);
}

bool    Form::isSigned()
{
    return (_signed);
}

int Form::getGradeRequired()
{
    return (_grade_required);
}

int Form::getGradeExecuted()
{
    return (_grade_execute);
}

void    Form::beSigned( Bureaucrat& which )
{
    if (which.getGrade() > _grade_required)
        throw GradeTooLowException();
    else
        this->_signed = 1;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Grade is too High ! ");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Grade is too low ! ");
}

std::ostream&   operator<<( std::ostream& stream, Form& Form )
{
    stream << "Form's name is : " << Form.getName() << ", is signed : " << Form.isSigned() << ", grade to sign : " << Form.getGradeRequired() << ", grade to exec :" << Form.getGradeExecuted() << "." << std::endl;
    return ( stream );
}