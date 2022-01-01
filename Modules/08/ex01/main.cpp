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
	//*******************************//
	std::vector<int>::iterator it;
	std::vector<int> tmp(10, 0);
	srand(time(0));
	generate(tmp.begin(), tmp.end(), rand);
	std::cout << "random generated: ";
	for (int i = 0; i < 10; i++)
	{
		// *it = i;
		// it++;
		tmp[i] %= 100;
		std::cout << tmp[i] << " ";
	}
	std::cout << std::endl;

	it = tmp.begin();

	std::vector<int> tmp2(10, 0);
	// tmp2.begin() = tmp.begin();
	std::vector<int>::iterator it2;
	it2 = tmp2.begin();
	std::cout << "copied: ";
	for (int i = 0; i < 10; i++)
	{
		*it2 = *it;
		it++;
		it2++;
		std::cout << tmp2[i] << " ";
	}
	std::cout << std::endl;

	Span sp3(9);
	std::cout << "sp3: ";
	sp3.addNumberRange(tmp2.begin(), tmp2.end());
	ft_print(sp3);
}
