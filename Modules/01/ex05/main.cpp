#include "Karen.hpp"

int main(void)
{
	Karen karen;
	void (Karen::*f)(std::string level);

	karen.complain("DEBUG");

	f = &Karen::complain;
	(karen.*f)("INFO");
	(karen.*f)("WARNING");
	(karen.*f)("ERROR");
}
