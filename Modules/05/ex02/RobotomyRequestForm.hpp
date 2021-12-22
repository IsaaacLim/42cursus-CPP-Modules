#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();

	std::string const _target;

public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	std::string getTarget(void) const;

	class RobotomizeException : public std::exception
	{
		const char *what() const throw();
	};

	void execute(Bureaucrat const &executor) const; //to be called by Bureaucrat
};

#endif
