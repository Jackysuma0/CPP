#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    private:
        Brain*  _ideas;
    public:
        Cat();
        ~Cat();
        Cat& operator=(const Cat &other);
        Cat(const Cat &other);
        void    makeSound() const;
        std::string	getIdeas( int ) const;
		void		setIdeas( std::string, int );
};
