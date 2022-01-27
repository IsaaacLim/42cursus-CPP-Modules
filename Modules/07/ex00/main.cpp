#include "whatever.hpp"

template <typename T>
void ft_display(T const &x, T const &y, char var1, char var2)
{
	std::cout << "---- Display ----\n";
	std::cout << var1 << " = " << x << ", " << var2 << " = " << y << std::endl;
	std::cout << "min( " << var1 << ", " << var2 << " ) = " << ::min(x, y) << std::endl;
	std::cout << "max( " << var1 << ", " << var2 << " ) = " << ::max(x, y) << std::endl;
}

int main(void)
{
	int a = 2;
	int b = 3;
	ft_display(a, b, 'a', 'b');
	::swap(a, b);
	ft_display(a, b, 'a', 'b');
	std::cout << "\n";

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	ft_display(c, d, 'c', 'd');
	std::cout << "\n";

	float e = 42.24f;
	float f = 42.24f;
	ft_display(e, f, 'e', 'f');
}
