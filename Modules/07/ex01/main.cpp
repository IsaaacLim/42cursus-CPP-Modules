#include "iter.hpp"

template <typename T>
void ft_print(T &var)
{
	std::cout << std::boolalpha << var << " ";
}

template <typename T>
void ft_toupper(T &var)
{
	if (var >= 'a' && var <= 'z')
		var -= ' ';
}

int main(void)
{
	int arr_size;

	// --- Integers --- //
	int int_arr[] = {1, 2, 3, 4, 5};
	arr_size = sizeof(int_arr) / sizeof(int_arr[0]);

	::iter(int_arr, arr_size, &ft_print);
	std::cout << std::endl;

	// --- Characters --- //
	char char_arr[] = {'a', 'b', 'C', 'D', '1', '2', '!', 'z'};
	arr_size = sizeof(char_arr) / sizeof(char_arr[0]);

	::iter(char_arr, arr_size, &ft_print);
	std::cout << std::endl;
	::iter(char_arr, arr_size, &ft_toupper);
	::iter(char_arr, arr_size, &ft_print);
	std::cout << std::endl;

	// --- Strings --- //
	std::string str_arr[] = {"This", "is", "a", "string"};
	arr_size = sizeof(str_arr) / sizeof(str_arr[0]);
	::iter(str_arr, arr_size, &ft_print);
	std::cout << std::endl;

	// --- Booleans --- //
	bool bool_arr[] = {true, false, true, true};
	arr_size = sizeof(bool_arr) / sizeof(bool_arr[0]);
	::iter(bool_arr, arr_size, &ft_print);
	std::cout << std::endl;
}
