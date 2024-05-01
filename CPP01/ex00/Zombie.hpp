#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <new>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();
		std::string	getName(void);
		void	setName(std::string name);
		void	announce(void);
};

#endif
