#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

/*
** Getter: Gets a private variable
** Setter: Allows user to set value to a private variable
** Usage: To allow limit contol to users
*/
class Sample {

public:
	Sample(void);
	~Sample(void);

	int	getFoo(void) const; //const because it won't be changed
	void	setFoo(int v);

private:
	int	_foo;
};

#endif
