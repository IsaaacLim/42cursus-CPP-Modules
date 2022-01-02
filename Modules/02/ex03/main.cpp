#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void ft_output(Point const &a, Point const &b, Point const &c, Point const &pt)
{
	std::cout << pt << ": ";
	if (bsp(a, b, c, pt))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not inside" << std::endl;
}

int main(void)
{
	Point const a(0, 0);
	Point const b(20, 0);
	Point const c(10, 30);

	Point const point1(0, 0);
	Point const point2(20, 0);
	Point const point3(10, 15);
	Point const point4(10, 30);
	Point const point5(-1, 0);
	Point const point6(20, 1);
	Point const point7(10, 31);

	std::cout << "Triangle: a" << a << " b" << b << " c" << c << "\n\n";
	ft_output(a, b, c, point1);
	ft_output(a, b, c, point2);
	ft_output(a, b, c, point3);
	ft_output(a, b, c, point4);
	ft_output(a, b, c, point5);
	ft_output(a, b, c, point6);
	ft_output(a, b, c, point7);

	// ***** Point class Copy constructor and Assignation operator test ***** //
	std::cout << "\n----- Point class Copy constructor & Assignation operator test -----\n";
	Point tmp(0, 0);
	Point tmp2(c);

	std::cout << "tmp" << tmp << "\n";
	tmp = b;
	std::cout << "tmp = b ... new tmp" << tmp << "\n";
	std::cout << "tmp2(c)... tmp2" << tmp2 << "\n";
	return 0;
}
