#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
    private:
    public:
        WrongCat();
        ~WrongCat();
        WrongCat& operator=(const WrongCat &other);
        WrongCat(const WrongCat &other);
        void    makeSound() const;
};