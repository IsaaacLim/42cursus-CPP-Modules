#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : _target(target), Form("Shruberry Creation", false, 145, 137)
{
	std::cout << "Shrub Form\t: Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other)
{
	*this = other;
	std::cout << "Shrub Form\t: Copy constructor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrub Form\t: Destructor\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	std::cout << "Shrub Form\t: Assignment operator\n";
	return *this;
}

// const char *ShrubberyCreationForm::FileOpenException::what() const throw()
// {
// 	return "*Shrubbery Creation Form failed to open file*";
// }

// const char *ShrubberyCreationForm::FileWriteException::what() const throw()
// {
// 	return "*Shruberry Creation Form failed to write out*";
// }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// Form::execute(executor);
	std::ofstream ofs;

	ofs.open((this->_target + (std::string) "_shubbery"), std::ostream::out | std::ostream::app);
	if (!ofs.is_open() || ofs.bad())
		throw "*Shrubbery Creation Form failed to open file*";
	ofs << ShrubberyCreationForm::trees[0] << std::endl;
	if (ofs.bad())
	{
		ofs.close();
		throw "*Shruberry Creation Form failed to write out*";
	}
	ofs.close();
}

std::string const ShrubberyCreationForm::trees[1] = {
	"      /\\\n"
	"     /\\*\\\n"
	"    /\\O\\*\\\n"
	"   /*/\\/\\/\\\n"
	"  /\\O\\/\\*\\/\\\n"
	" /\\*\\/\\*\\/\\/\\\n"
	"/\\O\\/\\/*/\\/O/\\\n"
	"      ||\n"
	"      ||\n"
	"      ||\n"};
