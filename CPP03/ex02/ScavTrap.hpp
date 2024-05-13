#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		~ScavTrap();
		std::string getName();
		int		getHitPoints();
		int		getEnergyPoints();
		int		getAttackDamage();
		void	attack(const std::string &target);
		void guardGate();
};

#endif
