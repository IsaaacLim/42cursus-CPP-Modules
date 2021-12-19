#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _learned(0)
{
	for (int i = 0; i < SKILL_AMOUNT; i++)
		this->_materias[i] = NULL;
	std::cout << "MSource\t\t: Default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource &other) : _learned(0)
{
	*this = other;
	// for (int i = 0; i < other._learned; i++)
	// 	this->learnMateria(other._materias[i]->clone());
	// for (int i = 0; i < SKILL_AMOUNT; i++) //?
	// 	this->_materias[i] = NULL;		   //?
	std::cout << "MSource\t\t: Copy constructor\n";
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _learned; i++)
		delete _materias[i];
	std::cout << "MSource\t\t: Destructor" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < this->_learned; i++)
		delete this->_materias[i];
	this->_learned = 0;
	for (int i = 0; i < rhs._learned; i++)
		this->learnMateria(rhs._materias[i]->clone());
	for (int i = 0; i < SKILL_AMOUNT; i++) //?
		this->_materias[i] = NULL;		   //?
	std::cout << "MSource\t\t: Assignmation operator\n";
	return *this;
}

//Source don't have to be unique
void MateriaSource::learnMateria(AMateria *skill)
{
	if (!skill)
		std::cout << RED "MSource\t\t: Invalid Materia to learn\n" RESET;
	else if (_learned >= SKILL_AMOUNT)
	{
		delete skill;
		std::cout << RED "MSource\t\t: Capacity too full to learn new Materia\n" RESET;
	}
	else
	{
		this->_materias[_learned++] = skill;
		std::cout << GREEN "MSource\t\t: Learned new materia\n" RESET;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *new_materia = NULL;

	for (int i = 0; i < _learned; i++)
	{
		if (type == _materias[i]->getType())
		{
			std::cout << GREEN "MSource\t\t: Created new materia\n" RESET;
			// new_materia = _materias[i]->clone();
			return (_materias[i]->clone());
		}
	}
	if (!new_materia)
		std::cout << RED "MSource\t\t: Failed to create materia\n" RESET;
	return new_materia;
}
