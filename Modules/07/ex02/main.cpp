#include "Array.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

// ********** Display test's label ****************************************** //
void ft_header(std::string str, char c)
{
	std::cout << c << BLUE "===================== " << str << " =====================\n" RESET;
}

void ft_title(std::string str, char c)
{
	std::cout << c << YELLOW "---------- " << str << " ----------\n" RESET;
}

// ****** Set Array value & Display Array value w/ Try-catch exception ****** //
template <typename T>
void ft_try_display(Array<T> const &arr, int const &idx)
{
	try
	{
		std::cout << arr[idx];
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "Display err: ";
		std::cerr << e.what() << " @ index: " << idx << RESET "\n";
	}
}

template <typename T>
void ft_try_set(Array<T> &arr, int const &idx, T const &value)
{
	try
	{
		arr[idx] = value;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "Assign. err: ";
		std::cerr << e.what() << " @ index: " << idx << RESET "\n";
	}
}

// ************************************************************************** //
int main(void)
{
	ft_header("INT", 0);
	Array<int> iNum;
	Array<int> iNum2 = Array<int>(3);

	ft_title("Accessing iNum (empty array)", 0);
	ft_try_set(iNum, 0, 10);
	ft_title("Setting & Displaying value to iNum2 until out of limits", '\n');
	for (int i = 0; i < 4; i++)
		ft_try_set(iNum2, i, i * 10);
	for (int i = 0; i < 4; i++)
	{
		ft_try_display(iNum2, i);
		std::cout << " ";
	}
	ft_title("Deep copy test with iNum2 & iNum3", '\n');
	Array<int> iNum3 = iNum2;
	std::cout << "iNum3: ";
	for (int i = 0; i < 3; i++)
	{
		ft_try_set(iNum3, i, i);
		ft_try_display(iNum3, i);
		std::cout << " ";
	}
	std::cout << "\niNum2: ";
	for (int i = 0; i < 3; i++)
	{
		ft_try_display(iNum2, i);
		std::cout << " ";
	}
	std::cout << "\n";

	ft_header("CHAR", '\n');
}
