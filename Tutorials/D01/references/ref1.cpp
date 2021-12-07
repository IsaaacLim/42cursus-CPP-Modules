#include <iostream>

/*
** References are different from pointers
**	- REF are like aliases for an existing variable
**	1) REF are pointers that is contant
**	2) REF are like a dereferenced pointer (no need to use * or & when displaying a value)
**	3) REF are never void
*/
int main()
{
	int numberOfBalls = 42;

	int *ballsPtr = &numberOfBalls;
	int &ballsRef = numberOfBalls; //reference pointing on numberOfBalls var. Can't change where this is pointing on anymore (no. 1)
	// int &ballsRef2;				   //can't do this. It's a reference pointing on nothing that can't be changed later (no.3)

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84; //no need * or & (no. 2)
	std::cout << numberOfBalls << std::endl;

	return (0);
}
