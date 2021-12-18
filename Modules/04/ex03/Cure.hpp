#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure(void);
	Cure(const Cure &other);
	~Cure(void);
	Cure &operator=(const Cure &rhs);

	AMateria *clone() const;
	void use(ICharacter &target) override;
};

#endif
