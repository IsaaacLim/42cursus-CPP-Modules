#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern\t: Default constructor\n"; }

Intern::Intern(Intern const &other)
{
	*this = other;
	std::cout << "Intern\t: Copy constructor\n";
}

Intern::~Intern() { std::cout << "Intern\t: Destructor\n"; }

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

const char *Intern::NoFormException::what() const throw()
{
	return "*Invalid form creation request. Forms available [shrubbery creation], [robotomy request], [presidential pardon]*";
}

Form *Intern::makeForm(std::string const &form, std::string const &target) const
{
	Form *ptr = NULL;
	int form_no;
	for (form_no = 0; form_no < 3; form_no++)
	{
		if (formNames[form_no] == form)
			break ;
	}
	switch (form_no)
	{
	case Shrub:
		ptr = new ShrubberyCreationForm(target);
		break;
	case Robo:
		ptr = new RobotomyRequestForm(target);
		break;
	case Pardon:
		ptr = new PresidentialPardonForm(target);
		break;
	default:
		throw NoFormException();
	}
	std::cout << "Intern creates [" << ptr->getFormName() << "] form\n";
	return (ptr);
}

//Can't seem to use this
// void Intern::setFormPtr(Form *ptr)
// {
// 	this->_form_ptr = ptr;
// }

std::string const Intern::formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
