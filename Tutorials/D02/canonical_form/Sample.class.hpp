#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

#include <iostream>

/*
** Canonical form is just a practise to standardize the structure of our codes
**	(this is still incomplete as it lacks a few more notions (eg: virtual))
**
** What's needed:
**	1. Default constructor
**	2. Copy of the constructor: constructor taking in a parameter (an instance we're defining) to make a copy of this class
**	3. Destructor
**	4. Equals (=) assignment operator: alloing us to make assignments from this class
*/
class Sample
{
private:
	int _foo;

public:
	Sample(void); // Canonical (default constructor)
	Sample(int const n);
	Sample(Sample const &src); // Canonical (copy of the constructor)
	~Sample();				   // Canonical (destructor)

	Sample &operator=(Sample const &rhs); // Canonical (equals assingment operator)

	int getFoo(void) const;
};

std::ostream &operator<<(std::ostream &o, Sample const &i);

#endif
