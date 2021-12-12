#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) { return; }

Point::Point(Point const &other)
{
	this->_x = other.getX();
	this->_y = other.getY();
}

Point::Point(float const x, float const y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::~Point(void) { return; }

Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return *this;
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}
