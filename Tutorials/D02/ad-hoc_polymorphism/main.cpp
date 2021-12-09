#include "Sample.class.hpp"

int main(void)
{
	Sample instance;
	Sample &ref = instance;

	float z = 3.142;

	instance.bar('a');
	instance.bar(42);
	instance.bar(z);
	instance.bar(ref);
}
