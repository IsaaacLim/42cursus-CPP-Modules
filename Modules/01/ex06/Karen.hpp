#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

enum e_level
{
	Debug,
	Info,
	Warning,
	Error
};

class Karen
{
private:
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
