#include <iostream>
#include <iomanip>

// ****** GENERIC TEMPLATE ************************************************* //
template <typename T, typename U>
class Pair
{
private:
	Pair<T, U>(void);

	T const &_lhs;
	U const &_rhs;

public:
	Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs)
	{
		std::cout << "Generic Template" << std::endl;
	}
	~Pair<T, U>(void) {}

	T const &fst(void) const { return this->_lhs; }
	U const &snd(void) const { return this->_rhs; }
};

// ****** PARTIAL SPECIALIZATION TEMPLATE *********************************** //
template <typename U>
class Pair<int, U>
{
private:
	Pair<int, U>(void);

	int _lhs;
	U const &_rhs;

public:
	Pair<int, U>(int const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs)
	{
		std::cout << "Int partial specialization" << std::endl;
	}
	~Pair<int, U>(void) {}

	int const &fst(void) const { return this->_lhs; }
	U const &snd(void) const { return this->_rhs; }
};

// ****** FULL SPECIALIZATION TEMPLATE ************************************** //
template <> //Still need to define empty template
class Pair<bool, bool>
{
private:
	Pair<bool, bool>(void);
	int _n; //Can store multiple booleans within the bits of a variable

public:
	Pair<bool, bool>(bool lhs, bool rhs)
	{
		std::cout << "Bool/bool full specialization" << std::endl;
		this->_n = 0;
		this->_n |= static_cast<int>(lhs) << 0; //tackle the least significant bit
		this->_n |= static_cast<int>(rhs) << 1; //Left shift to tackle the 2nd bit
	}
	~Pair<bool, bool>(void) {}

	bool fst(void) const { return this->_n & 0x01; } //return 1st bit of _n
	bool snd(void) const { return this->_n & 0x02; } //return 2nd bit of _n
};

// ************************************************************************** //
template <typename T, typename U>
std::ostream &operator<<(std::ostream &o, Pair<T, U> const &p)
{
	o << "Pair( " << p.fst() << ", " << p.snd() << " )";
	return o;
}

//std::boolalpha is a iomanipulator to display true/false rather than 1/0
std::ostream &operator<<(std::ostream &o, Pair<bool, bool> const &p)
{
	o << std::boolalpha << "Pair( " << p.fst() << ", " << p.snd() << " )";
	return o;
}
