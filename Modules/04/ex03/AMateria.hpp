#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

#include <iostream>

class AMateria;
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	//Canonical form
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &rhs);

	//Specified functions
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
	std::string const &getType(void) const;
};

#endif
