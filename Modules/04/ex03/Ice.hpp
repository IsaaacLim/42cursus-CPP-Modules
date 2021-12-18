#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice(void);
	Ice(const Ice &other);
	~Ice(void);
	Ice &operator=(const Ice &rhs);

	AMateria *clone() const;
	void use(ICharacter &target) override; //might not be able to use override
};

#endif
