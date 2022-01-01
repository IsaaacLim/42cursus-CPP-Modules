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

#endif
