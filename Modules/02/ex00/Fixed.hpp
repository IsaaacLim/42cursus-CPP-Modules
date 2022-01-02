#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fpValue;
	static const int _fracBits = 8; //number of fractional bits
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &other); //copy of the contructor

	Fixed &operator=(Fixed const &rhs); //Assignment operator overload

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
