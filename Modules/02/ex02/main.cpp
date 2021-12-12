#include "Fixed.hpp"

#define INT_ARR 4

void ft_display_comparison(Fixed *int_arr)
{
	std::cout << "---- COMPARISON OPERATIONS ----" << std::endl;
	std::cout << "values: {";
	for (int i = 0; i < INT_ARR; i++)
		std::cout << int_arr[i] << ", ";
	std::cout << "}" << std::endl;

	for (int i = 0; i < INT_ARR - 1; i++)
	{
		for (int j = i + 1; j < INT_ARR; j++)
		{
			if (int_arr[i] == int_arr[j])
				std::cout << int_arr[i] << "\t=\t" << int_arr[j] << std::endl;
			if (int_arr[i] != int_arr[j])
				std::cout << int_arr[i] << "\t!=\t" << int_arr[j] << std::endl;
			if (int_arr[i] > int_arr[j])
				std::cout << int_arr[i] << "\t>\t" << int_arr[j] << std::endl;
			if (int_arr[i] < int_arr[j])
				std::cout << int_arr[i] << "\t<\t" << int_arr[j] << std::endl;
			if (int_arr[i] >= int_arr[j])
				std::cout << int_arr[i] << "\t>=\t" << int_arr[j] << std::endl;
			if (int_arr[i] <= int_arr[j])
				std::cout << int_arr[i] << "\t<=\t" << int_arr[j] << std::endl;
		}
	}
}

void ft_arithmetic_operation()
{
	Fixed a(5.25f);
	Fixed b(20.5f);

	std::cout << "---- ARITHMETIC OPERATIONS ----" << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << b << " / " << a << " = " << b / a << std::endl;
}

void ft_increments_decrements()
{
	Fixed a(800);

	std::cout << "---- INCREMENTS ----" << std::endl;
	std::cout << "num   = " << a << std::endl;
	std::cout << "++num = " << ++a << std::endl;
	std::cout << "num++ = " << a++ << std::endl;
	std::cout << "num   = " << a << std::endl;
	std::cout << "---- DECREMENTS ----" << std::endl;
	std::cout << "--num = " << --a << std::endl;
	std::cout << "num-- = " << a-- << std::endl;
	std::cout << "num   = " << a << std::endl;
}

void ft_min_max(void)
{
	Fixed const a(10.551f);
	Fixed b(10.555f);
	Fixed c;

	std::cout << "---- MIN MAX ----" << std::endl;
	c = Fixed::min(a, b);
	std::cout << "min: " << c << std::endl;
	c = Fixed::max(a, b);
	std::cout << "max: " << c << std::endl;
}

void ft_pdf_test()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "---- PDF test ----" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

int main(void)
{
	Fixed int_arr[INT_ARR] = {0, 20.535f, 30, 20.535f};

	ft_display_comparison(int_arr);
	ft_arithmetic_operation();
	ft_increments_decrements();
	ft_min_max();
	ft_pdf_test();
}
