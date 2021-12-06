#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

//static is used to for non-member function/attribute
class Sample
{

public:
	Sample(void);
	~Sample(void);

	static int getNbInst(void);

private:
	static int _nbInst;
};
#endif
