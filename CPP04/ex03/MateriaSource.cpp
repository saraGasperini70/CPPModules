#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Standard MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource *src)
{
	std::cout << "Copy MateriaSource constructor called." << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Standard MateriaSource deconstructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *newMat)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = newMat;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i]->getType() == type)
		{
			return this->_materias[i]->clone();
		}
	}
	return (0);
}

