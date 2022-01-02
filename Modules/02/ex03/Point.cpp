#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) { return; }

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &other) : _x(other.getX()), _y(other.getY()) {}

Point::~Point(void) { return; }

Point &Point::operator=(Point const &rhs)
{
	Fixed *tmpX = const_cast<Fixed *>(&this->_x);
	Fixed *tmpY = const_cast<Fixed *>(&this->_y);
	if (this != &rhs)
	{
		*tmpX = rhs.getX();
		*tmpY = rhs.getY();
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

std::ostream &operator<<(std::ostream &out, Point const &var)
{
	out << "(" << var.getX() << ", " << var.getY() << ")";
	return out;
}
