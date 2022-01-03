#include "Mutantstack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
	std::cout << "Constructor\n";
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const &other) : std::stack<T, Container>(other)
{
	std::cout << "Copy constructor\n";
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack const &rhs)
{
	std::cout << "Assignment operator\n";
	std::stack<T, Container>::operator=(rhs);
	return *this;
}


template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
	return std::stack<T, Container>::c.begin();
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
	return std::stack<T, Container>::c.end();
}

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin(); //another syntax
}
