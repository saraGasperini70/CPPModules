#ifndef ADOG_HPP
# define ADOG_HPP

# include "AAnimal.hpp"

class ADog: public AAnimal
{
	public:
		ADog();
		ADog(ADog *src);
		~ADog();
		ADog &operator=(const ADog &src);
		void	makeSound(void) const;
};

#endif
