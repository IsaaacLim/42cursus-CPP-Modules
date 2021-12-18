#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	~MateriaSource(void);
	MateriaSource &operator=(const MateriaSource &rhs);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
