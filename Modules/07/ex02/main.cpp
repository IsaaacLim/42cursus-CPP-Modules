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
	ft_header("STRING", 0);
	Array<std::string> str = Array<std::string>(5);

	str[0] = "First";
	str[1] = "Second";
	str[2] = "1234567890";
	str[3] = "";
	str[4] = "!@#$%^&*()";
	for (int i = 0; i < 5; i++)
	{
		ft_try_display(str, i);
		std::cout << "\n";
	}

	// ---------------------------------------------------------------------- //
	ft_header("NUMBERS", '\n');
	std::cout << YELLOW "INT\t: " RESET;
	Array<int> iNum = Array<int>(10);
	for (int i = 0; i < 10; i++)
	{
		ft_try_set(iNum, i, i * 10);
		ft_try_display(iNum, i);
		std::cout << " ";
	}
	std::cout << "\n";
	std::cout << YELLOW "FLOAT\t: " RESET;
	Array<float> fNum = Array<float>(10);
	for (int i = 0; i < 10; i++)
	{
		ft_try_set(fNum, i, (i + .42f));
		ft_try_display(fNum, i);
		std::cout << " ";
	}
	std::cout << "\n";

	// ---------------------------------------------------------------------- //
	ft_header("Deep copy test", '\n');
	Array<int> iNum2 = iNum;
	std::cout << YELLOW "iNum2\t: " RESET;
	for (int i = 0; i < 10; i++)
	{
		ft_try_set(iNum2, i, i * -20);
		ft_try_display(iNum2, i);
		std::cout << " ";
	}
	std::cout << YELLOW "\niNum\t: " RESET;
	for (int i = 0; i < 10; i++)
	{
		ft_try_display(iNum, i);
		std::cout << " ";
	}
	std::cout << "\n";

	// ---------------------------------------------------------------------- //
	ft_header("ERRORS", '\n');
	Array<int> iNum3;
	ft_title("Accessing iNum3 (empty array)", 0);
	ft_try_set(iNum3, 0, 10);

	ft_title("Setting & Displaying value of iNum until out of limits", '\n');
	for (int i = 0; i < 11; i++)
		ft_try_set(iNum, i, i * 10);
	for (int i = 0; i < 11; i++)
	{
		ft_try_display(iNum, i);
		std::cout << " ";
	}
	std::cout << std::endl;
}
