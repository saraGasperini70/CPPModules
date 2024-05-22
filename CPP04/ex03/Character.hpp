#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*_inventory[4];
		AMateria	*_floor[100];
		std::string	_name;

	public:
		Character(std::string name);
		Character(Character *src);
		~Character();

		Character &operator=(const Character &src);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};
#endif
