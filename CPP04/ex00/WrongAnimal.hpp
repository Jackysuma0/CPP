#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "iostream"
#include "string.h"

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(const std::string type);
        virtual ~WrongAnimal();
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal& operator=(const WrongAnimal &other);
        void    makeSound() const;
        std::string getType() const;
        void    setType( const std::string type_ref );
};

#endif