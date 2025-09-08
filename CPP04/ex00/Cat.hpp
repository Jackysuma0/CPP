#include "Animal.hpp"

class   Cat : public Animal
{
    private:
    public:
        Cat();
        ~Cat();
        Cat& operator=(const Cat &other);
        Cat(const Cat &other);
        void    makeSound() const;
};
