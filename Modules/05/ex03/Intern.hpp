#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum e_forms
{
	Shrub,
	Robo,
	Pardon
};

class Intern
{
private:
	static std::string const formNames[3];
	// Form *_form_ptr;

public:
	Intern();
	Intern(Intern const &other);
	virtual ~Intern();
	Intern &operator=(Intern const &rhs);

	class NoFormException : public std::exception
	{
		virtual const char *what() const throw();
	};

	Form *makeForm(std::string const &form, std::string const &target) const;

	// void setFormPtr(Form *ptr);
};

#endif
