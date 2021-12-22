#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("Pres. Pardon", false, 25, 5), _target(target)
{
	std::cout << "Pres F.\t: Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other)
{
	*this = other;
	std::cout << "Pres F.\t: Copy constructor\n";
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "Pres F.\t: Destructor\n"; }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void)rhs;
	std::cout << "Pres F.\t: Assignment operator\n";
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox\n";
}

std::string PresidentialPardonForm::getTarget(void) const { return this->_target; }
