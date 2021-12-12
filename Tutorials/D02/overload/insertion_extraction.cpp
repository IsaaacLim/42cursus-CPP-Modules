#include <iostream>

/*
** From: https://youtu.be/RQnYiiLtt38
** This method doesn't allow us to access private members
*/
class Overload
{
public:
	std::string firstName;
	std::string lastName;
};

/*
** Insertion operator overload
**	'&' cuz we want to return a reference to the same object so we don't make copies everytime
**	1st arg is the param to the left of the operator, 2nd is to the right
**	2nd arg is not going to be changed so 'const'
**
**	Write to out then return it
*/
std::ostream &operator<<(std::ostream &out, Overload const &obj)
{
	out << "First name: " << obj.firstName << "\nLast name: " << obj.lastName;
	return (out);
}

/*
** Extraction operator overload
**	'>>' will automatically skip spaces, separating first and last name
*/
std::istream &operator>>(std::istream &in, Overload &obj)
{
	in >> obj.firstName >> obj.lastName;
	// return (obj); //nope
	return (in);
}

int main()
{
	Overload user;
	user.firstName = "Isaac";
	user.lastName = "Lim";

	std::cout << user << std::endl;

	std::cout << "Input full name: ";
	std::cin >> user;
	std::cout << user << std::endl;
}
