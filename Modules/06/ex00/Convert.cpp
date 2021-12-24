#include "Convert.hpp"

Convert::Convert(std::string const &literal) : _input(literal)
{
	this->evaluateInput();
	this->cast();
}

Convert::~Convert() { std::cout << "Destructor" << std::endl; }

void Convert::evaluateInput(void)
{
	std::stringstream ss;

	size_t input_len = this->_input.length();

	if (input_len == 1 && !(std::isdigit(this->_input[0])))
	{
		this->_type = eChar;
		this->_cValue = this->_input[0];
		return;
	}
}

void Convert::cast(void)
{
	switch (this->_type)
	{
	case eChar:
	{
		this->_iValue = static_cast<int>(this->_cValue);
		this->_fValue = static_cast<float>(this->_cValue);
		this->_dValue = static_cast<double>(this->_cValue);
		break;
	}
	case eInt:
	{
		std::cout << "Type is int\n";
		break;
	}
	case eFloat:
	{
		std::cout << "Type is float\n";
		break;
	}
	case eDouble:
	{
		std::cout << "Type is double\n";
		break;
	}
	default:
	{
		std::cerr << "Something wrong with cast()\n";
		break;
	}
	}
}

char Convert::getCValue(void) const { return this->_cValue; }

int Convert::getIValue(void) const { return this->_iValue; }

float Convert::getFValue(void) const { return this->_fValue; }

double Convert::getDValue(void) const { return this->_dValue; }

std::ostream &operator<<(std::ostream &out, Convert const &instance)
{
	out << "char\t: " << instance.getCValue() << "\n";
	out << "int\t: " << instance.getIValue() << "\n";
	out << "float\t: " << instance.getFValue() << "\n";
	out << "double\t: " << instance.getDValue() << "\n";
	return out;
}
