#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

#include <iostream>

/*
** Also known as function overloading
** Function names are the same, but we specialize them based on their parameters
*/

class Sample
{

public:
	Sample(void);
	~Sample(void);

	void bar(char const c) const;
	void bar(int const n) const;
	void bar(float const z) const;
	void bar(Sample const &i) const;
};

#endif
