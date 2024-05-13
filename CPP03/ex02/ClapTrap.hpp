#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string	_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		~ClapTrap();
		std::string getName();
		int		getHitPoints();
		int		getEnergyPoints();
		int		getAttackDamage();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		ClapTrap &operator=(const ClapTrap &src);
};

#endif
