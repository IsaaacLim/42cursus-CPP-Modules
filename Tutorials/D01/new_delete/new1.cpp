#include <iostream>
#include <string>

//This writing style works the same as creating class .hpp & .cpp
class Student
{
private:
	std::string _login;

public:
	Student(std::string login);
	~Student(void);
};

Student::Student(std::string login) : _login(login)
{
	std::cout << "Student " << this->_login << " is born" << std::endl;
}

Student::~Student()
{
	std::cout << "Student " << this->_login << " died" << std::endl;
}

int main()
{
	Student bob = Student("bfubar");	  //creating instance on stack
	Student *jim = new Student("jfubar"); //creating instance on heap

	delete jim; //like free. Jim is destroyed

	return (0); //bob is destroyed
}
