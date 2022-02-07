#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
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
int easyfind(T array, int find) // Vector, List, Deque, Set, Multiset
{
	typename T::iterator found;

	found = std::find(array.begin(), array.end(), find);
	if (found == array.end())
		throw CantFindException();
	return (std::distance(array.begin(), found));
}

template <typename T, typename U>
int easyfind(std::map<T, U> array, int find) // Map
{
	typename std::map<T, U>::iterator it;

	for (it = array.begin(); it != array.end(); it++)
	{
		if (it->second == find)
			break;
	}
	if (it == array.end())
		throw CantFindException();
	return (std::distance(array.begin(), it));
}

template <typename T, typename U> // Multimap
int easyfind(std::multimap<T, U> array, int find)
{
	typename std::multimap<T, U>::iterator it;

	for (it = array.begin(); it != array.end(); it++)
	{
		if (it->second == find)
			break;
	}
	if (it == array.end())
		throw CantFindException();
	return (std::distance(array.begin(), it));
}

#endif
