#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(0));
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Generated class A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated class B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated class C" << std::endl;
			return new C();
		default:
			std::cout << "Generated unknown class" << std::endl;
			return (0);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified class C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Identified class A" << std::endl;
		(void)a;
	}
	catch (std::bad_cast &e) {}

	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Identified class B" << std::endl;
		(void)b;
	}
	catch (std::bad_cast &e) {}

	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Identified class C" << std::endl;
		(void)c;
	}
	catch (std::bad_cast &e) {}
}
