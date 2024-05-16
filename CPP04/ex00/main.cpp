# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	delete i;
	j->makeSound();
	delete j;
	meta->makeSound();
	delete meta;

	std::cout << "Wrong classes: " << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* kitty = new WrongCat();
	kitty->makeSound(); //won´t output the cat sound!
	delete kitty;
	wrong->makeSound();
	delete wrong;
	return 0;
}
