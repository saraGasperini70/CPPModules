#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_materias[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource *src);
		~MateriaSource();
		void learnMateria(AMateria *newMat);
		AMateria* createMateria(std::string const & type);

};

#endif
