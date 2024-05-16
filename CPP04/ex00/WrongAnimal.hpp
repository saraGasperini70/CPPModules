#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		//Constructor/deconstructor
		WrongAnimal();
		WrongAnimal(WrongAnimal &src);
		virtual ~WrongAnimal();

		//Getters/Setters
		std::string getType(void) const;
		void setType(std::string type);

		//Member functions
		WrongAnimal &operator=(const WrongAnimal &src);
		void	makeSound(void) const;
};

#endif
