#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

/*
** If n == 0, allocate memory to _arr as Default constructor
**	so destructor can delete _arr appropriately
*/
template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _size;

public:
	Array<T>(void) : _arr(new T()), _size(0) {}
	Array<T>(unsigned int n) : _size(n)
	{
		if ((int)n <= 0)
		{
			if ((int)n < 0) //Just a safeguard
				std::cout << "error: bad alloc" << std::endl;
			this->_arr = new T();
			this->_size = 0;
			return;
		}
		this->_arr = new T[n];
	}
	Array<T>(Array<T> const &other)
	{
		if (other._size == 0)
			this->_arr = new T();
		else
			this->_arr = new T[other.size()];
		this->_size = other.size();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = other._arr[i];
	}
	~Array<T>(void)
	{
		if (_size > 0)
			delete[] _arr;
		else
			delete _arr;
	}

	Array<T> &operator=(Array<T> const &rhs)
	{
		std::cout << "Assignment Operator\n";
		this->_arr = new T[rhs.size()];
		this->_size = rhs.size();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = rhs._arr[i];
		return *this;
	}

	T &operator[](unsigned int idx) const
	{
		if (idx >= this->_size)
			throw Array<T>::OverLimitsException();
		return (this->_arr[idx]);
	}

	unsigned int size(void) const { return this->_size; }

	class OverLimitsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("*overlimit*");
		}
	};
};

#endif
