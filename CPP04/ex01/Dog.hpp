#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal
{
    private:
        Brain*  _ideas;
    public:
        Dog();
        ~Dog();
        Dog& operator=(const Dog &other);
        Dog(const Dog &other);
        void    makeSound() const;
        std::string	getIdeas( int ) const;
		void		setIdeas( std::string, int );
};