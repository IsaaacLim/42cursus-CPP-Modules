#include "default_type.tpp.hpp"

int main(void)
{
	Vertex<int> v1(12, 23, 34);
	Vertex<> v2(12, 23, 34); //set to Float by default

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
}
