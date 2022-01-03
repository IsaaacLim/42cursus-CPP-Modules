/*
** For Module08 ex02
** Stack vs Deque
*/

#include <iostream>
#include <deque>
#include <stack>

/*
** About STACK container
**	Stack is a higher level container from DEQUE
**	Stack is a LIFO deque & doesn't contain iterator functions
**	c++98 functions: push, pop, empty, size, top
*/
void ft_stack(void)
{
	std::stack<int> stack;

	std::cout << "========== STACK ==========\n";
	for (int i = 0; i < 5; i++)
		stack.push(i);
	std::cout << "Stack size: " << stack.size() << "\n";
	while (!stack.empty())
	{
		std::cout << stack.top() << "\n";
		stack.pop();
	}
	std::cout << "Stack size: " << stack.size() << "\n";
}

/*
** About DEQUE container
**	1. An indexed sequenced conatiner
**	2. Allows fast insertion at both beginning and end
*/
void ft_deque(void)
{
	std::deque<int> deque = {20, 30, 40};
	std::deque<int>::iterator itS = deque.begin();
	std::deque<int>::iterator itE = deque.end();

	std::cout << "\n========== DEQUE ==========\n";
	for (int i = 0; i < 5; i++)
		deque.push_back(i);
	// while (itS != itE)
	// std::cout << *itS++ << "\n";
	while (!deque.empty())
	{
		std::cout << deque.back() << "\n";
		deque.pop_back();
	}
	while (itS != itE) //still works lol
		std::cout << *itS++ << "\n";
	std::cout << deque[0] << "\n";
	std::cout << deque[5] << "\n";
	std::cout << deque.size() << "\n";
}

int main(void)
{
	ft_stack();
	ft_deque();
}
