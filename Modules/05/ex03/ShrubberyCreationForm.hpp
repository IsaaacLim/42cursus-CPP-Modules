#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();

	std::string const _target;
	static std::string const trees[2];

public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	std::string getTarget(void) const;

	class FileOpenException : public std::exception
	{
		const char *what() const throw();
	};
	class FileWriteException : public std::exception
	{
		const char *what() const throw();
	};

	void execute(Bureaucrat const &executor) const; //to be called by Bureaucret::executeForm
};

#endif
