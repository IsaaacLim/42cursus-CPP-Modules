#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample instance; //class instantation
	
	instance.foo = 42;
	std::cout << "instance foo: " << instance.foo << std::endl;

	instance.bar();

	return 0;
}
