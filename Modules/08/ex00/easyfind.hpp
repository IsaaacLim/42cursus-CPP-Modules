#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

class CantFindException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("*can't be found*");
	}
};

template <typename T>
int easyfind(T array, int find)
{
	typename T::iterator found;

	found = std::find(array.begin(), array.end(), find);
	if (found == array.end())
		throw CantFindException();
	return (std::distance(array.begin(), found));
}

#endif
