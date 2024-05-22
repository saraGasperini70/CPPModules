#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Cure: public AMateria
{
	private:

	public:
		Cure();
		Cure(Cure &src);
		~Cure();

		Cure &operator=(const Cure &src);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
