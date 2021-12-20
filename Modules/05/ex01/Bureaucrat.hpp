#ifndef BUREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <iostream>

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
private:
	Bureaucrat();

	std::string const _name;
	int _grade;

public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	virtual ~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string const &getName(void) const;
	int getGrade(void) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public: //to allow main to catch this specific exception
		virtual const char *what() const throw();
	};

	void incrementGrade(void);
	void decrementGrade(void);

	void signForm(Form &form) const; //to be called by Form::beSigned()
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &instance);

#endif
