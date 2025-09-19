#include "Intern.hpp"
#define NBR_FORMS 3

Intern::Intern()
{
    std::cout << "Default constructor for Intern was called" << std::endl;
}

Intern::Intern( const Intern& other )
{
    std::cout << "Intern's copy constructor called" << std::endl;
    *this = other;
}


Intern::~Intern()
{
    std::cout << "Intern's destructor called" << std::endl;
}

Intern& Intern::operator=( const Intern& other )
{
    if ( this == &other )
        return ( *this );
    return ( *this );
}

// AForm*	Intern::makeForm( const std::string formName, const std::string target )
// {
//     std::string formNames[NBR_FORMS] = { "presidential pardon", "robotomy request", "shrubbery creation" };
//     AForm*      formList[NBR_FORMS] = {  new PresidentialPardonForm( target ), new RobotomyRequestForm( target ), new ShrubberyCreationForm( target ) };
//     int i;
//     int j;

//     i = 0;
//     j = -1;
//     while (i < NBR_FORMS)
//     {
//         if (formNames[i] == formName)
//             j = i;
//         i++;
//     }
//     if (j != -1 )
//     {
//         i = 0;
//         while (i < NBR_FORMS)
//         {
//             if (i != j)
//                 delete (formList[i]);
//             i++;
//         }
//         std::cout << "Intern creates " << formNames[j] << std::endl;
//         return ( formList[j] );
//     }
//     else
//     {
//         i = 0;
//         while (i < NBR_FORMS)
//             delete(formList[i++]);
//         std::cout << "Intern can't find the requested form!" << std::endl;
//         return ( NULL );
//     }
// }

AForm* Intern::makeForm(const std::string formName, const std::string target) {
    const std::string formNames[NBR_FORMS] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    int index = -1;
    int i = 0;
    while (i < NBR_FORMS)
    {
        if (formNames[i] == formName)
        {
            index = i;
            break;
        }
        i++;
    }
    if (index == -1)
    {
        std::cout << "Intern can't find the requested form!" << std::endl;
        return (NULL);
    }
    AForm* createdForm = NULL;
    switch (index)
    {
        case 0:
            createdForm = new PresidentialPardonForm(target);
            break;
        case 1:
            createdForm = new RobotomyRequestForm(target);
            break;
        case 2:
            createdForm = new ShrubberyCreationForm(target);
            break;
    }
    std::cout << "Intern creates " << formNames[index] << std::endl;
    return (createdForm);
}
