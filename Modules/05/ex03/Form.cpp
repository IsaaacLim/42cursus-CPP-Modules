#include "Form.hpp"

Form::Form(std::string const &formName, bool isSigned, int const &gradeToSign, int const &gradeToExecute) : _formName(formName), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "Form\t: Constructor\n";
}

Form::Form(Form const &other) : _formName(other._formName), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target)
{
	*this = other;
	std::cout << *this;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "Form\t: Copy constructor\n";
}

Form::~Form() { std::cout << "Form\t: Destructor" << std::endl; }

Form &Form::operator=(Form const &rhs)
{
	this->_isSigned = rhs.getIsSigned();
	this->_target = rhs.getTarget();
	std::cout << "Form\t: Assignment operator\n";
	return *this;
}

std::string Form::getFormName(void) const { return this->_formName; }

bool Form::getIsSigned(void) const { return this->_isSigned; }

int Form::getGradeToSign(void) const { return this->_gradeToSign; }

int Form::getGradeToExecute(void) const { return this->_gradeToExecute; }

std::string Form::getTarget(void) const { return this->_target; }

void Form::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("*Form grade is too HIGH*");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("*Form grade is too LOW*");
}

const char *Form::ExecutorGradeTooLowException::what() const throw()
{
	return ("*Executor grade is too Low*");
}

const char *Form::FormUnsignedException::what() const throw()
{
	return ("*Form is still unsigned*");
}

void Form::beSigned(Bureaucrat const &person)
{
	if (person.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException(); //pdf requested for Form's exception but it doesn't make sense
	else
		person.signForm(*this);
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw Form::FormUnsignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw Form::ExecutorGradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &instance)
{
	out << "\nForm information - [" << instance.getFormName() << "]\n";
	out << "\tSigned?\t\t: ";
	if (instance.getIsSigned())
		out << "Yes\n";
	else
		out << "No\n";
	out << "\tGrade to sign\t: " << instance.getGradeToSign() << "\n";
	out << "\tGrade to execute: " << instance.getGradeToExecute() << "\n";
	out << "\tTarget\t\t: " << instance.getTarget() << "\n";
	return out;
}
