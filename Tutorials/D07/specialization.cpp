#include "specialization.tpp.hpp"

int main()
{
	Pair<int, int> p1(4, 2);
	Pair<std::string, float> p2(std::string("Pi"), 3.14f); //WSL can't handle float wel
	Pair<float, bool> p3(4.2f, true);					   //WSL can't handle float well
	Pair<bool, bool> p4(false, true);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
}
