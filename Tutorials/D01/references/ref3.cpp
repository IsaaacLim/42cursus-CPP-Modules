#include <iostream>
#include <string>

/*
** Final note(which to use):
**	- Pointers: when at some point it shouldn't exist or should change
**	- Refs: should always exist and never change
*/
class Student
{
private:
	std::string _login;

public:
	Student(std::string const &login) : _login(login) {}
	std::string &getLoginRef() { return this->_login; }
	std::string const &getLoginRefConst() const { return this->_login; } //just to display
	std::string *getLoginPtr() { return &(this->_login); }
	std::string const *getLoginPtrConst() const { return &(this->_login); } //just to display
	// ~Student();
};

int main()
{
	Student bob = Student("bob");
	Student const jim = Student("jim");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	// jim.getLoginRef() = "jimmy"; //can't change const
	bob.getLoginRef() = "bobby";
	std::cout << bob.getLoginRef() << std::endl;
	std::cout << bob.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtr()) << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << std::endl;

	*(bob.getLoginPtr()) = "bobbie";
	std::cout << bob.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << std::endl;
}
