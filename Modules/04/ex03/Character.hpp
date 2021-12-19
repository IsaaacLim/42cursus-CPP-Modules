#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define SKILL_AMOUNT 4

class Character : public ICharacter
{
private:
	AMateria *_materias[SKILL_AMOUNT];
	std::string _name;
	int _equipped;

public:
	//Canonical form
	Character(void);
	Character(std::string const &name);
	Character(const Character &other);
	~Character(void);
	Character &operator=(const Character &rhs);

	//Interface functions
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
