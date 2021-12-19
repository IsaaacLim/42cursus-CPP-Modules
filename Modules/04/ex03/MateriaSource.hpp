#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SKILL_AMOUNT 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[SKILL_AMOUNT];
	int _learned;

public:
	//Canonical form
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	~MateriaSource(void);
	MateriaSource &operator=(const MateriaSource &rhs);

	//Interface functions
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
