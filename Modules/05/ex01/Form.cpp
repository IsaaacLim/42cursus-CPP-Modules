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

Form::Form(Form const &other) : _formName(other._formName), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "Form\t: Copy constructor\n";
}

Form::~Form() { std::cout << "Form\t: Destructor\n"; }

Form &Form::operator=(Form const &rhs)
{
	this->_isSigned = rhs.getIsSigned();
	std::cout << "Form\t: Assignment operator\n";
	return *this;
}

std::string Form::getFormName(void) const { return this->_formName; }

bool Form::getIsSigned(void) const { return this->_isSigned; }

int Form::getGradeToSign(void) const { return this->_gradeToSign; }

int Form::getGradeToExecute(void) const { return this->_gradeToExecute; }

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

void Form::beSigned(Bureaucrat const &person)
{
	if (person.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException(); //pdf requested for Form's exception but it doesn't make sense
	else
		// person.signForm(*this);
		return;
}

std::ostream &operator<<(std::ostream &out, Form const &instance)
{
	out << "[" << instance.getFormName() << "] form\n";
	out << "\tSigned?\t: ";
	if (instance.getIsSigned())
		out << "Yes\n";
	else
		out << "No\n";
	out << "\tGrade to sign\t: " << instance.getGradeToSign() << "\n";
	out << "\tGrade to execute\t: " << instance.getGradeToExecute() << "\n";
	return out;
}
