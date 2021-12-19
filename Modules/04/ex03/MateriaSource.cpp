#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _learned(0)
{
	for (int i = 0; i < SKILL_AMOUNT; i++)
		this->_materias[i] = NULL;
	std::cout << "MSource\t: Default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	std::cout << "MSource\t: Copy constructor\n";
}

MateriaSource::~MateriaSource(void) { std::cout << "MSource\t: Destructor" << std::endl; }

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	// this->....
	(void)rhs;
	std::cout << "MSource\t: Assignmation operator\n";
	return *this;
}

void MateriaSource::learnMateria(AMateria *skill)
{
	// AMateria *new_skill = new AMateria();
	if ((!skill) || _learned >= SKILL_AMOUNT)
		std::cout << "MSource\t: Unable to learn new Materia\n";
	else
	{
		*this->_materias[_learned++] = *skill;
		std::cout << "MSource\t: Learned new materia\n";
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *new_materia = NULL;

	for (int i = _learned; i < SKILL_AMOUNT; i++)
	{
		if (type == _materias[i]->getType())
		{
			new_materia = _materias[i]->clone();
			std::cout << "MSource\t: Created new materia\n";
		}
	}
	if (!new_materia)
		std::cout << "MSource\t: Unknown materia type. Failed to create materia\n";
	return new_materia;
}
