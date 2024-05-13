#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragtrap);
		~FragTrap();
		std::string getName();
		int		getHitPoints();
		int		getEnergyPoints();
		int		getAttackDamage();
		void	highFivesGuys(void);
};

#endif
