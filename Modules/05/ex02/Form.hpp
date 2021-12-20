#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdbool.h>
#include <fstream>

class Form;
#include "Bureaucrat.hpp"

class Form
{
private:
	Form();

	std::string const _formName;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	Form(std::string const &formName, bool isSigned, int const &gradeToSign, int const &gradeToExecute);
	Form(Form const &other);
	virtual ~Form();
	Form &operator=(Form const &rhs);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	std::string getFormName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute() const;

	void setIsSigned(bool isSigned);
	void beSigned(Bureaucrat const &person);
};

std::ostream &operator<<(std::ostream &out, Form const &instance);

#endif
