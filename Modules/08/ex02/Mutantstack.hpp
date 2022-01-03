#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>
#include <iterator>

/*
** Some implementation is directly within the header file, 
**	whilst some in Mutantstack.cpp for syntax practice 
** Ref: https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators#:~:text=The%20std%3A%3Astack%20does%20expose%20its%20underlying%20container%20(and%20therefore%20iterators)%20to%20subclasses%20through%20its%20protected%20interface.%20The%20std%3A%3Astack%27s%20underlying%20container%20object%20corresponds%20to%20the%20(protected)%20data%20member%20c.%20So%20if%20you%20want%20to%20access%20them%2C%20you%20could%20extend%20std%3A%3Astack%20a%20little.
*/
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	using std::stack<T, Container>::c;

public:

	MutantStack();
	MutantStack(MutantStack const &other);
	~MutantStack()
	{
		std::cout << "Destructor" << std::endl;
	};
	MutantStack &operator=(MutantStack const &rhs);

	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;

	typename Container::iterator begin();
	typename Container::iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend()
	{
		return c.rend();
	};
};

template class MutantStack<char, std::deque<char> >;
template class MutantStack<std::string, std::deque<std::string> >;
template class MutantStack<int, std::deque<int> >;
template class MutantStack<float, std::deque<float> >;
template class MutantStack<double, std::deque<double> >;
template class MutantStack<bool, std::deque<bool> >;

#endif
