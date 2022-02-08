#include "Span.hpp"
#include <list>
#include <string.h> //strncmp

void ft_printTitle(std::string title, char c)
{
	std::cout << c << "---------- " << title << " ----------\n";
}

void ft_printArr(Span clone)
{
	for (long unsigned int i = 0; i < clone.getArr().size(); i++)
		std::cout << clone.getArr()[i] << " ";
	std::cout << std::endl;
}

void ft_findSpan(Span clone)
{
	try
	{
		std::cout << "minspan: " << clone.shortestSpan() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "maxspan: " << clone.longestSpan() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(int argc, char *argv[])
{
	//  ***** BASIC ********************************************************* //
	Span sp = Span(5);

	ft_printTitle("Basic", 0);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(-10);
	sp.addNumber(4);
	try
	{
		sp.addNumber(5);
		sp.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	ft_printArr(sp);
	std::cout << "minspan: " << sp.shortestSpan() << "\n";
	std::cout << "maxspan: " << sp.longestSpan() << "\n";

	// ***** NO SPAN ******************************************************** //
	Span sp2 = Span(1);

	ft_printTitle("No Span", '\n');
	try
	{
		sp2.addNumber(2);
		sp2.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	ft_printArr(sp2);
	ft_findSpan(sp2);

	//***** ADDING w/ RANGE OF ITERATORS *************************************//
	Span sp3(20);
	std::vector<int> tmp(20, 0);
	srand(time(0));

	ft_printTitle("Adding with Iterators", '\n');
	generate(tmp.begin(), tmp.end(), rand); //randomly generate numbers
	for (int i = 0; i < 20; i++)			//trim the numbers
		tmp[i] %= 100;
	sp3.addNumberRange(tmp.begin(), tmp.end());
	ft_printArr(sp3);
	ft_findSpan(sp3);

	//***** ADDING w/ RANGE OF ITERATORS (List) ******************************//
	Span sp4(5);
	std::list<int> tmp2;

	ft_printTitle("Adding with Iterators (List)", '\n');
	for (int i = 0; i < 5; i++)
		tmp2.push_back(i);
	sp4.addNumberRange(tmp2.begin(), tmp2.end());
	ft_printArr(sp4);
	ft_findSpan(sp4);

	// ***** 10000 NUMBERS TEST ********************************************* //
	Span sp5(10000);
	std::vector<int> tmp3(10000, 0);

	ft_printTitle("10000 Numbers Test", '\n');
	generate(tmp3.begin(), tmp3.end(), rand);
	sp5.addNumberRange(tmp3.begin(), tmp3.end());
	if (argc == 2 && !(strncmp(argv[1], "show", 5)))
		ft_printArr(sp5);
	else
		std::cout << "\033[3;33mrun <./span show> to display container values\033[0m\n";
	ft_findSpan(sp5);
}
