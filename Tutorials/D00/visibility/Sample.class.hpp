#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

/*
** If visibility is not specified, class attributs are private by default;
*/
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

/*
** Structs are the same as classes.
** By default, the attributes are public.
** In practise, we can't to use classes more
** Anything a struct can do, classes can as well
*/
struct Sample2
{
	int foo;

	Sample2(void);
	~Sample2(void);

	void bar2(void) const;
};
#endif
