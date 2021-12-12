#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	//Supposed to be const but can't initialize then
private:
	Fixed _x;
	Fixed _y;

public:
	Point(void);
	Point(Point const &other);
	Point(float const x, float const y);
	~Point(void);

	Point &operator=(Point const &rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif
