# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// delete i;
	// j->makeSound();
	// delete j;
	// meta->makeSound();
	// delete meta;
	Animal a;
	{
		Animal b=a;
	}
	return 0;
}
