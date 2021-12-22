#include <iostream>

class A
{
};
class B
{
};

/*
** Can use A or B class to contruct a C class
**	Meaning we somehow converted A & B class to C class
**
** The explicit keyword specifies that we must explicitly use the constructor
*/
class C
{
public:
	C(A const &nothing) { return; }
	explicit C(B const &nothing) { return; }
};

// ************************************************************************** //

void f(C const &nothing) //this function takes a member of C class
{
	return;
}

// ************************************************************************** //

/*
** Since calling the f function requires a C class, the compiler will implicitly
**	conver the A / B class to a C class
*/
int main(void)
{
	f(A()); //Implicit conversion Ok
	// f(B());					//Implicit conversion NOT Ok
	f(static_cast<C>(B())); //Explicit conversion Ok
}
