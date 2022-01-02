#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

/*
** Converts integer to fixed point value with 8 fractional bits
**	Bit shift for (num * 2 ^ 8)
*/
Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpValue = (num << Fixed::_fracBits);
	return;
}

/*
** Converts integer to fixed point value with 8 fractional bits
**	Source: https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
*/
Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpValue = roundf(num * (1 << Fixed::_fracBits));
	return;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fpValue = other.getRawBits();
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_fpValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

//fixed point to integer
int Fixed::toInt(void) const
{
	int temp;

	temp = this->_fpValue >> Fixed::_fracBits;
	return temp;
}

//fixed point to floating point value
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
