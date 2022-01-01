#include "Span.hpp"

// void ft_tryAdd(int newNum)
// {
// 	try
// 	{

// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// }

void ft_print(Span clone)
{

	for (long unsigned int i = 0; i < clone.getArr().size(); i++)
		std::cout << clone.getArr()[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(-10);
	sp.addNumber(4);
	try
	{
		sp.addNumber(58);
		sp.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	ft_print(sp);
	std::cout << "minspan: " << sp.shortestSpan() << "\n";
	std::cout << "maxspan: " << sp.longestSpan() << "\n";
	ft_print(sp);

	Span sp2 = Span(1);
	sp2.addNumber(2);
	try
	{
		sp2.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "minspan: " << sp2.shortestSpan() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "maxspan: " << sp2.longestSpan() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
