#include "Animal.hpp"

class   Dog : public Animal
{
    private:
    public:
        Dog();
        ~Dog();
        Dog& operator=(const Dog &other);
        Dog(const Dog &other);
        void    makeSound() const;
};