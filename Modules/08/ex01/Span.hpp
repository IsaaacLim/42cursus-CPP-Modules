#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	Span();

	unsigned int _size;
	std::vector<int> _arr;

public:
	Span(unsigned int size);
	Span(Span const &other);
	~Span();
	Span &operator=(Span const &rhs);

	void addNumber(int newNum);
	template <typename IT>
	void addNumberRange(IT begin, IT end);
	int shortestSpan(void);
	int longestSpan(void);

	unsigned int getSize(void);
	std::vector<int> getArr(void);
	void setSize(unsigned int newSize);

	class FullStorageException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class NoSpanException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

template <typename IT>
void Span::addNumberRange(IT begin, IT end)
{
	IT it;

	for (it = begin; it != end; it++)
	{
		try
		{
			addNumber(*it);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

#endif
