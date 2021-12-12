#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point const a(0, 0);
	Point const b(20, 0);
	Point const c(10, 30);

	// Point const point(10, 15);
	Point const point(20, 1);
	// Point const point(-1, 0);

	if (bsp(a, b, c, point))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not inside" << std::endl;

	return 0;
}
