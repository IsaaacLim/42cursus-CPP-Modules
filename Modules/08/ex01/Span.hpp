#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
private:
	Span();

	unsigned int size;

public:
	Span(unsigned int size);
	Span(Span const &other);
	~Span();
	Span &operator=(Span const &rhs);

	void addNumber(int newNum);
	int shortestSpan();
	int longestSpan();

	class FullStorageException : public std::exception
	{
		virtual const char *what() throw();
	};
	class NoSpanException : public std::exception
	{
		virtual const char *what() throw();
	};
};

#endif
