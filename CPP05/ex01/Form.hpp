#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
// #include <cstdbool>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int   _grade_execute;
        const int   _grade_required;
        bool _signed;
    public:
        Form();
        Form ( const std::string name, int grade, int grade_req );
        ~Form();
        Form( const Form &other );
        Form& operator=( const Form &other );
        void    beSigned( Bureaucrat& which );
        bool    isSigned();
        std::string getName() const;
         class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        int getGradeRequired();
        int getGradeExecuted();
};

std::ostream&	operator<<(std::ostream&, Form&);

#endif