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

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "*Shrubbery Creation Form failed to open file*";
}

const char *ShrubberyCreationForm::FileWriteException::what() const throw()
{
	return "*Shruberry Creation Form failed to write out*";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor); //test manual error with this error
	std::string const outfileName = this->_target + "_shrubbery";
	std::ofstream ofs;

	ofs.open(outfileName.data(), std::ostream::out | std::ostream::app);
	if (!ofs.is_open() || ofs.bad())
		throw FileOpenException();
	ofs << ShrubberyCreationForm::trees[2] << std::endl;
	if (ofs.bad())
	{
		ofs.close();
		throw FileWriteException();
	}
	ofs.close();
	std::cout << "Shrubbery trees has been planted in [" << outfileName << "]\n";
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

std::string const ShrubberyCreationForm::trees[3] = {
	"      /\\\n"
	"     /\\*\\\n"
	"    /\\O\\*\\\n"
	"   /*/\\/\\/\\\n"
	"  /\\O\\/\\*\\/\\\n"
	" /\\*\\/\\*\\/\\/\\\n"
	"/\\O\\/\\/*/\\/O/\\\n"
	"      ||\n"
	"      ||\n"
	"      ||\n",
	"           \\/ |    |/\n"
	"        \\/ / \\||/  /_/___/_\n"
	"         \\/   |/ \\/\n"
	"    _\\__\\_\\   |  /_____/_\n"
	"           \\  | /          /\n"
	"  __ _-----`  |{,-----------~\n"
	"            \\ }{\n"
	"             }{{\n"
	"             }}{\n"
	"            {{}\n"
	"       , -=-~{ .-^- _\n"
	"             `}\n"
	"              {\n",
	"	            .        +          .      .          .\n"
	"     .            _        .                    .\n"
	"  ,              /;-._,-.____        ,-----.__\n"
	" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
	"	 `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
	"                      ,    `./  \\:. `.   )==-'  .\n"
	"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
	".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
	"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
	"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
	"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
	"              \\:  `  X` _| _,\\/'   .-'\n"
	".               \":._:`\\____  /:'  /      .           .\n"
	"                    \\::.  :\\/:'  /              +\n"
	"	   .                 `.:.  /:'  }      .\n"
	"           .           ):_(:;   \\           .\n"
	"                      /:. _/ ,  |\n"
	"                   . (|::.     ,`                  .\n"
	"     .                |::.    {\\\n"
	"                      |::.\\  \\ `.\n"
	"                      |:::(\\    |\n"
	"              O       |:::/{ }  |                  (o\n"
	"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
	"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
	"      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\n"};
