#include <iostream>
#include <typeinfo>
#include <exception>

/*
** Dynamic cast runs on run-time
**	Hence, the program may still compile even with a bad cast type
*/

class Parent
{
public:
	virtual ~Parent(void) {}
};

class Child1 : public Parent
{
};
class Child2 : public Parent
{
};

// *************************************************************************** //

int main(void)
{
	Child1 a;		//Reference value
	Parent *b = &a; //Implicit upcast -> OK

	/*
	**Explicit downcast -> Run during run time
	** Dynamic Cast using a POINTER
	*/
	Child1 *c = dynamic_cast<Child1 *>(b);
	if (c == NULL)
		std::cout << "Conversion is NOT Ok" << std::endl;
	else
		std::cout << "Conversion is Ok" << std::endl;

	/*
	**Explicit downcast -> Run during run time
	** Dynamic cast using a REFERENCE
	** (reference can't be NULL so it won't return NULL if it fails)
	*/
	try
	{
		Child2 &d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is Ok" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cerr << "Conversion is NOT Ok: " << bc.what() << '\n';
		return 0;
	}
	return 0;
}
