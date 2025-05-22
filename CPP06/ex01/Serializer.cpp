#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer copy constructor called." << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	std::cout << "Serializer deconstructor called." << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		// No members to copy
	}
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	std::cout << "Serializer serialize called." << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	std::cout << "Serializer deserialize called." << std::endl;
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator<<(std::ostream &out, const Serializer &src)
{
	(void)src;
	out << "Serializer object." << std::endl;
	return (out);
}
