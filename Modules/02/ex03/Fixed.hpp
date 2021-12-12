#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fpValue;
	static const int _fracBits = 8;

public:
	Fixed(void);
	Fixed(int const num);
	Fixed(float const num);
	Fixed(Fixed const &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;

	Fixed &operator=(Fixed const &rhs);

	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;

	Fixed operator+(Fixed const &rhs);
	Fixed operator-(Fixed const &rhs);
	Fixed operator*(Fixed const &rhs);
	Fixed operator/(Fixed const &rhs);

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &v1, Fixed &v2);
	static Fixed const &min(Fixed const &v1, Fixed const &v2);
	static Fixed &max(Fixed &v1, Fixed &v2);
	static Fixed const &max(Fixed const &v1, Fixed const &v2);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
