#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int   _grade_execute;
        const int   _grade_required;
        bool _signed;
    public:
        AForm();
        AForm ( const std::string name, int grade, int grade_req );
        virtual ~AForm();
        AForm( const AForm &other );
        AForm& operator=( const AForm &other );
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
        int getGradeRequired() const;
        int getGradeExecuted() const;
        virtual void    execute( const Bureaucrat& executor ) const = 0;
};

std::ostream&	operator<<(std::ostream&, AForm&);

#endif