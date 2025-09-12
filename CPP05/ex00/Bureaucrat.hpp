#include <iostream>
#include <string.h>

class Bureaucrat
{
    protected:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat( std::string name, int grade );
        Bureaucrat( const std::string name );
        ~Bureaucrat();
        Bureaucrat( const Bureaucrat& other );
        Bureaucrat& operator=(Bureaucrat const &other);
        std::string getName() const;
        int         getGrade() const;
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        void         decrementGrade( int i );
        void         incrementGrade( int i);
};
