#include <iostream>

/*
** Type cast operators has an 'operator' keyword
** 'static_cast' are used to make sure that we casts are compatible
*/
class Foo
{
private:
	float _v;

public:
	Foo(float const v) : _v(v) {}

	float getV(void) { return this->_v; }

	operator float() { return this->_v; }
	operator int() { return static_cast<int>(this->_v); }
};

// ************************************************************************** //

int main(void)
{
	Foo a(420.042f);
	float b = a;
	int c = a;

	std::cout << a.getV() << "\n";
	std::cout << b << "\n";
	std::cout << c << std::endl;
}
