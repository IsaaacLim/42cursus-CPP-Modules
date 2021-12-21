#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shruberry Creation", false, 145, 137), _target(target)
{
	std::cout << "Shrub F.: Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other)
{
	*this = other;
	std::cout << "Shrub F.: Copy constructor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrub F.: Destructor\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	std::cout << "Shrub F.: Assignment operator\n";
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
	(void)executor;
	// Form::execute(executor);
	std::string const outfileName = this->_target + "_shrubbery";
	std::ofstream ofs;

	ofs.open(outfileName.data(), std::ostream::out | std::ostream::app);
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
