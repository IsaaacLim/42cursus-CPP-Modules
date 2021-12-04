#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

class Sample
{
public:
	int publicFoo;

	Sample(void);
	~Sample(void);

	void publicBar(void) const;

private:
	int _privateFoo;

	void _privateBar(void) const;
};

#endif
