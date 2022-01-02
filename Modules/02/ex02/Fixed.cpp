#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fpValue(0) { return; }

Fixed::Fixed(int const num)
{
	this->_fpValue = num << Fixed::_fracBits;
}

Fixed::Fixed(float const num)
{
	this->_fpValue = roundf(num * (1 << Fixed::_fracBits));
}

Fixed::Fixed(Fixed const &other)
{
	this->_fpValue = other.getRawBits();
}

Fixed::~Fixed(void) { return; }

int Fixed::getRawBits(void) const
{
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

int Fixed::toInt(void) const
{
	int temp;

	temp = this->_fpValue >> Fixed::_fracBits;
	return temp;
}

float Fixed::toFloat(void) const
{
	float temp;

	temp = (float)this->_fpValue / (float)(1 << Fixed::_fracBits);
	return temp;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_fpValue = rhs.getRawBits();
	return *this;
}

bool Fixed::operator==(Fixed const &rhs) const
{
	// if (this->_fpValue == rhs.getRawBits())
	if (_fpValue == rhs._fpValue) //works too
		return true;
	return false;
}

//another syntax
bool Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_fpValue != rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	if (_fpValue > rhs._fpValue)
		return true;
	return false;
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (_fpValue < rhs._fpValue);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (_fpValue >= rhs._fpValue);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_fpValue <= rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	Fixed temp;

	temp._fpValue = _fpValue + rhs._fpValue;
	return (temp);
}

//Another syntax
Fixed Fixed::operator-(Fixed const &rhs)
{
	Fixed temp;

	temp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (temp);
}

/*
** Another syntax
** Multiply into a larger sized variable, then right shift by the number of bits of fixed point precision
**	source: https://stackoverflow.com/questions/14008330/how-do-you-multiply-two-fixed-point-numbers
*/
Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed temp(*this);

	temp.setRawBits((_fpValue * rhs._fpValue) >> Fixed::_fracBits);
	// temp.setRawBits(_fpValue * rhs._fpValue / (1 << Fixed::_fracBits)); //same
	return (temp);
}

/*
** Promote the numerator then divide
**	source: https://stackoverflow.com/questions/8506317/fixed-point-unsigned-division-in-c?rq=1
*/
Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed temp;

	temp._fpValue = (_fpValue << Fixed::_fracBits) / rhs._fpValue;
	return (temp);
}

Fixed Fixed::operator++()
{
	this->_fpValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fpValue++;
	return temp;
}

Fixed Fixed::operator--()
{
	this->_fpValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fpValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &v1, Fixed &v2)
{
	if (v1 < v2)
		return (v1);
	return (v2);
}

Fixed const &Fixed::min(Fixed const &v1, Fixed const &v2)
{
	if (v1 < v2)
		return v1;
	return v2;
}

Fixed &Fixed::max(Fixed &v1, Fixed &v2)
{
	if (v1 > v2)
		return (v1);
	return (v2);
}

Fixed const &Fixed::max(Fixed const &v1, Fixed const &v2)
{
	if (v1 > v2)
		return (v1);
	return (v2);
}
