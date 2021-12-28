#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, size_t const &arr_len, void (*func)(T &var))
{
	for (size_t i = 0; i < arr_len; i++)
		(func)(arr[i]);
}

#endif
