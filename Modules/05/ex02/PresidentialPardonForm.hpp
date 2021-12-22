#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();

	std::string const _target;

public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	std::string getTarget(void) const;

	void execute(Bureaucrat const &executor) const; //to be called by Bureaucrat
};

#endif
