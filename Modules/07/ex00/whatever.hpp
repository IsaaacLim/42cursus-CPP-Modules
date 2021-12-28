#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
	std::cout << "   * Swapped *\n";
}

template <typename T, typename U>
T const &max(T const &x, U const &y)
{
	return (x > y ? x : y);
}

template <typename T, typename U>
T const &min(T const &x, U const &y)
{
	return (x < y ? x : y);
}

#endif
