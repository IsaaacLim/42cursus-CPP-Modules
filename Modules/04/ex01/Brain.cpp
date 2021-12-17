#include "Brain.hpp"

Brain::Brain(void) { std::cout << "Brain\t: Default constructor\n"; }

Brain::Brain(const Brain &brain)
{
	*this = brain;
	std::cout << "Brain\t: Copy constructor\n";
}

Brain::~Brain(void) { std::cout << "Brain\t: Destructor\n"; }

Brain &Brain::operator=(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain\t: Assignment operator\n";
	return *this;
}
