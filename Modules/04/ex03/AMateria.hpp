#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
protected:
	std::string type;

public:
	//Canonical form
	//virtual these functions?
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	~AMateria();
	AMateria &operator=(const AMateria &rhs);

	//Specified functions
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
	std::string const &getType(void) const;
};

#endif
