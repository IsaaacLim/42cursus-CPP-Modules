#include "Fixed.hpp"
#include <cmath>

//Convers integerto fixed (8) point value
Fixed::Fixed(void) : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

//Convers integerto fixed (8) point value
Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpValue = (num << Fixed::_fracBits);
	return;
}

//Converts floating point to fixed (8) point value
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
