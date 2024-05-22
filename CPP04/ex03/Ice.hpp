#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Ice: public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice &src);
		~Ice();

		Ice &operator=(const Ice &src);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
