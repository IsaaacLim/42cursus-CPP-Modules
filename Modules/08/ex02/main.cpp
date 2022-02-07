#include "Mutantstack.hpp"
#include <stdbool.h>

#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

void ft_title(std::string title, char c)
{
	std::cout << c << YELLOW;
	std::cout << "==================== " << title << " ====================\n";
	std::cout << RESET;
}

int main()
{
	ft_title("INT", 0);
	MutantStack<int> mStack;

	mStack.push(1);
	mStack.push(10);
	mStack.push(42);
	mStack.push(-180);

	std::cout << BLUE "print MutantStack with deque iterator\n" RESET;
	// for (auto i : mStack)
	for (std::deque<int>::iterator i = mStack.begin(); i != mStack.end(); i++)
		std::cout << *i << " ";
	std::cout << "\n";

	std::cout << BLUE "\nMutantStack's iterator\n" RESET;
	MutantStack<int>::iterator it = mStack.begin();
	MutantStack<int>::iterator ite = mStack.end();
	MutantStack<int>::reverse_iterator itrb = mStack.rbegin();
	MutantStack<int>::reverse_iterator itre = mStack.rend();
	std::cout << "using iterator.begin()\t: " << *it << "\n";
	std::cout << "using iterator.end()\t: " << *(ite - 1) << "\n";
	std::cout << "using iterator.rbegin()\t: " << *(itrb + 2) << "\n";
	std::cout << "using iterator.rend()\t: " << itre[-1] << "\n";
	*it = 100;
	*(ite - 1) = 4200;
	itrb[1] = 300;
	itre[- 2] = 200;
	std::cout << "new MutantStack\t\t: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";

	std::cout << BLUE "\nCopy Constructor\n" RESET;
	MutantStack<int> mStack2(mStack);
	for(MutantStack<int>::iterator it = mStack2.begin(); it != mStack2.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << BLUE "\nAssignment Operator\n" RESET;
	MutantStack<int> mStack3;
	mStack3 = mStack;
	for(MutantStack<int>::iterator it = mStack3.begin(); it != mStack3.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	ft_title("STD::STRING", '\n');
	MutantStack<std::string> strStack;

	strStack.push("This");
	strStack.push("is");
	strStack.push("a");
	strStack.push("string");
	std::cout << BLUE "print with MutantStack's iterator\n" RESET;
	for(MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); it++)
		std::cout << *it << " ";
	std::cout << BLUE "\nprint with Stack functions\n" RESET;
	while (!strStack.empty())
	{
		std::cout << strStack.top() << "\n";
		strStack.pop();
	}

	ft_title("FLOAT", '\n');
	MutantStack<float> fltStack;
	for (int i = 5; i > 0; i--)
		fltStack.push(i * 2.2f);
	while (fltStack.size() > 0)
	{
		std::cout << fltStack.top() << "\n";
		fltStack.pop();
	}

	ft_title("BOOL", '\n');
	MutantStack<bool> boolStack;

	boolStack.push(true);
	boolStack.push(false);
	boolStack.push(0);
	boolStack.push(1);
	boolStack.push(2);
	boolStack.push(-1);
	for(MutantStack<bool>::iterator it = boolStack.begin(); it != boolStack.end(); it++)
		std::cout << std::boolalpha << *it << " ";
	std::cout << "\n\n";
}
