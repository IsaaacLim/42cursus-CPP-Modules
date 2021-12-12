#include "Point.hpp"

/*
** Ref: https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
*/
Fixed ft_area(Point const a, Point const b, Point const c)
{
	Fixed area1 = a.getX() * (b.getY() - c.getY());
	Fixed area2 = b.getX() * (c.getY() - a.getY());
	Fixed area3 = c.getX() * (a.getY() - b.getY());
	Fixed actual_area = (area1 + area2 + area3) / Fixed(2.0f);

	if (actual_area < 0)
		actual_area = actual_area * (Fixed(-1));
	return (actual_area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle = ft_area(a, b, c);
	Fixed A1 = ft_area(point, b, c);
	Fixed A2 = ft_area(a, point, c);
	Fixed A3 = ft_area(a, b, point);
	return (triangle == (A1 + A2 + A3));
}
