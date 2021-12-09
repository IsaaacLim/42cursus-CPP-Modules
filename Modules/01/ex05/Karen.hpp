#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen;

typedef struct s_complain
{
	std::string level;
	void (Karen::*func_ptr)(void);
} t_complain;

class Karen
{
private:
	t_complain complains[4];
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);

public:
	Karen(void);
	~Karen(void);

	void complain(std::string level);
};

#endif
