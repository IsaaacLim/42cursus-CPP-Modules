#include <iostream>
#include <stdint.h>

struct Data
{
	std::string str;
	int num;
	float numf;
};

uintptr_t serialize(Data *ptr)
{
	// return ((uintptr_t)ptr); // Implicit promotion
	return (reinterpret_cast<uintptr_t>(ptr)); // Explicit promotion (project requirement)
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator<<(std::ostream &out, Data const &instance)
{
	out << "str\t: " << instance.str << "\n";
	out << "num\t: " << instance.num << "\n";
	out << "float\t: " << instance.numf << std::endl;
	return (out);
}

int main()
{
	Data ori;
	uintptr_t converted;
	Data *reverted;

	ori.str = "Hello there this is a very long string";
	ori.num = 42;
	ori.numf = 42.42e32f;

	std::cout << "--- ORI ---\n";
	std::cout << ori << "\n";

	std::cout << "--- SERIALIZED ---\n";
	converted = serialize(&ori);
	std::cout << converted << "\n\n";

	std::cout << "--- DESERIALIZED ---\n";
	reverted = deserialize(converted);
	std::cout << *reverted;
}
