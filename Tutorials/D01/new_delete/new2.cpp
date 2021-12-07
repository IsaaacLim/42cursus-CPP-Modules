#include <iostream>
#include <string>

//This writing style is even more compact
class Student
{
private:
	std::string _login;

public:
	Student() : _login("ldefault")
	{
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}
	~Student()
	{
		std::cout << "Student " << this->_login << " died" << std::endl;
	}
};

//Creating sizeof(42) allocs
int main()
{
	Student *students = new Student[42];

	delete[] students;
}
