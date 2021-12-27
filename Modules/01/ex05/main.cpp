#include "Karen.hpp"

int main(void)
{
	Karen karen;
	void (Karen::*f)(std::string level);

	karen.complain("DEBUG");

	//Test to show that program was implimented using pointers to member complain function
	f = &Karen::complain;
	(karen.*f)("INFO");
	(karen.*f)("WARNING");
	(karen.*f)("ERROR");
}
