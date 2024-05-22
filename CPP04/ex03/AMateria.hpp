#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "Character.hpp"
# include "MateriaSource.hpp"

class ICharacter;
class Character;
class ImateriaSource;
class MateriaSource;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria &src);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		void setType(std::string type);

		AMateria &operator=(const AMateria &src);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
