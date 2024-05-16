# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "AAnimal.hpp"
# include "ADog.hpp"

int main()
{
	// const AAnimal* meta = new AAnimal();
	std::cout << "ADog class with abstract parent class AAnimal: " << std::endl;
	const AAnimal* j = new ADog();
	std::cout << "Type: " << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;

	std::cout << "Cat class: " << std::endl;
	const Animal* i = new Cat();
	std::cout <<  "Type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	delete i;
	// meta->makeSound();
	// delete meta;

	std::cout << "Testing copy constructor: " << std::endl;
	Animal a;
	{
		Animal b=a;
	}
	return 0;
}
