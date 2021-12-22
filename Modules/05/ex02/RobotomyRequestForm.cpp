#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("Robotomy Request", false, 72, 45), _target(target)
{
	std::cout << "Robo F.\t: Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other)
{
	*this = other;
	std::cout << "Robo F.\t: Copy constructor\n";
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "Robo F.\t: Destructor" << std::endl; }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void)rhs;
	std::cout << "Robo F.\t: Assignment operator\n";
	return *this;
}

const char *RobotomyRequestForm::RobotomizeException::what() const throw()
{
	return "*Robotomize failed. What an unlucky day*";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "~~ Drilling noises ~~ ... ... ... ";
	Form::execute(executor);
	time_t t;
	srand((unsigned)time(&t));
	if ((rand() % 2) != 0)
		throw RobotomizeException();
	std::cout << "Feeling lucky? [" << this->_target << "] has been robotomized!\n";
}

std::string RobotomyRequestForm::getTarget(void) const { return this->_target; }
