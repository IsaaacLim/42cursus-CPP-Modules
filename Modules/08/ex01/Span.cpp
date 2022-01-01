#include "Span.hpp"

Span::Span(unsigned int size) : _size(size) {}

Span::Span(Span const &other)
{
	this->_size = other._size;
	this->_arr = other._arr;
}

Span::~Span() {} //.clear()

Span &Span::operator=(Span const &rhs)
{
	this->_size = rhs._size;
	this->_arr = rhs._arr;
	return *this;
}

void Span::addNumber(int newNum)
{
	if (_arr.size() == _size)
		throw FullStorageException();
	this->_arr.push_back(newNum);
}

int Span::shortestSpan(void)
{
	std::vector<int>::iterator min;
	std::vector<int> arrCopy;
	int firstMin;

	if (_arr.size() < 2)
		throw NoSpanException();
	arrCopy = _arr;
	min = std::min_element(arrCopy.begin(), arrCopy.end());
	firstMin = *min;
	arrCopy.erase(min);
	min = std::min_element(arrCopy.begin(), arrCopy.end());
	return (*min - firstMin);

	// 	std::vector<int>::iterator x;
	// for (x = arrCopy.begin(); x != arrCopy.end(); ++x)
	// 	std::cout << *x << " ";
	// std::cout << std::endl;
}

unsigned int Span::getSize(void) { return this->_size; }

void Span::setSize(unsigned int newSize) { this->_size = newSize; }

std::vector<int> Span::getArr(void) { return this->_arr; }

const char *Span::FullStorageException::what() const throw()
{
	return "*exceeded object size*";
}

const char *Span::NoSpanException::what() const throw()
{
	return "*no span*";
}
