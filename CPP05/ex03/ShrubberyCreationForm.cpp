#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
    std::cout << "Default constructor for ShrubberyCreationForm has been called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string name ) : AForm(name, 145, 137)
{
    std::cout << "Name constructor for ShrubberyCreationForm has been called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm(other)
{
    std::cout << "ShrubberyCreationForm's copy constructor called" << std::endl;
    // *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm's copy deconstructor called" << std::endl;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& exec) const
{
    std::string shrubbery;

    if ( exec.getGrade() > getGradeRequired() )
        throw AForm::GradeTooLowException();
    else {
    
        std::ofstream ofstream;

        shrubbery = exec.getName() + "_shrubbery";
        ofstream.open( shrubbery.c_str() );
        if ( ofstream.fail() ) {
        
            std::cout << "Can't create file " << exec.getName() << "_shrubbery" << std::endl;
            return ;
        }
        ofstream << "       ###" << std::endl
                 << "      #o###"<< std::endl
                 << "    #####o###"<< std::endl
                 << "   #o#\\#|#/###"<< std::endl
                 << "    ###\\|/#o#"<< std::endl
                 << "     # }|{  #"<< std::endl
                 << "       }|{"<< std::endl << std::endl;
        ofstream.close();
    } 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& ref ) {

    if ( this == &ref )
        return ( *this );
    AForm::operator=( ref );
    return ( *this );
}