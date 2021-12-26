#include "Convert.hpp"

Convert::Convert(std::string const &literal) : _input(literal)
{
	std::cout << "Constructor\n\n";
	this->evaluateInput();
	this->cast();
	if (!Convert::ft_isascii(_cValue))
		_cValue = -1;
	else if (!Convert::ft_isprint(_cValue))
		_cValue = -2;
}

Convert::~Convert() { std::cout << "Destructor" << std::endl; }

void Convert::evaluateInput(void)
{
	std::stringstream ss;
	int i = 0;

	size_t input_len = _input.length();

	//Char
	if (input_len == 1 && !(std::isdigit(_input[0])))
	{
		_type = eChar;
		_cValue = _input[0];
	}
	//Float special case
	else if (_input == "nanf" || _input == "inff" || _input == "+inff" || _input == "-inff")
	{
		std::cout << "Input\t: " << _input << "\n";
		_type = eFloat;
		_fValue = atof(_input.c_str());
		std::cout << "Stored (flt)\t: " << _fValue << "\n";
	}
	//Double special case
	else if (_input == "nan" || _input == "inf" || _input == "+inf" || _input == "-inf")
	{
		std::cout << "Input\t: " << _input << "\n";
		_type = eDouble;
		_dValue = strtod(_input.c_str(), NULL); //alt function
		std::cout << "Stored (dbl)\t: " << _dValue << "\n";
	}
	//Other numbers
	else
	{
		_type = eInt;
		if (_input[0] == '+' || _input[0] == '-')
			ss << _input[i++];
		for (; std::isdigit(_input[i]) && (size_t)i < input_len; i++)
			ss << _input[i];
		if (_input[i] == '.')
		{
			ss << _input[i++];
			_type = eDouble;
		}
		for (; std::isdigit(_input[i]) && (size_t)i < input_len; i++)
			ss << _input[i];
		if (_input[i] == 'e' && (_input[i + 1] == '+' || _input[i + 1] == '-' || std::isdigit(_input[i + 1])))
		{
			ss << _input[i++];
			if (_input[i] == '+' || _input[i] == '-')
				ss << _input[i++];
			_type = eDouble;
		}
		for (; std::isdigit(_input[i]) && (size_t)i < input_len; i++)
			ss << _input[i];
		if (_input[i] == 'f' && (size_t)i == input_len - 1 && _type == eDouble)
			_type = eFloat;
		else if ((size_t)i != input_len)
		{
			std::cout << "i = " << i << "input_len = " << input_len << "\n";
			_type = -1;
		}
		switch (_type)
		{
		case eInt:
			ss >> _iValue;
			break;
		case eFloat:
			ss >> _fValue;
			break;
		case eDouble:
			ss >> _dValue;
			break;
		default:
			break;
		}
	}
}

void Convert::cast(void)
{
	switch (this->_type)
	{
	case eChar:
	{
		std::cout << "Type is char\n";
		this->_iValue = static_cast<int>(this->_cValue);
		this->_fValue = static_cast<float>(this->_cValue);
		this->_dValue = static_cast<double>(this->_cValue);
		break;
	}
	case eInt:
	{
		std::cout << "Type is int\n";
		this->_cValue = static_cast<char>(this->_iValue);
		this->_fValue = static_cast<float>(this->_iValue);
		this->_dValue = static_cast<double>(this->_iValue);
		break;
	}
	case eFloat:
	{
		std::cout << "Type is float\n";
		this->_cValue = static_cast<char>(this->_fValue);
		this->_iValue = static_cast<int>(this->_fValue);
		this->_dValue = static_cast<double>(this->_fValue);
		break;
	}
	case eDouble:
	{
		std::cout << "Type is double\n";
		this->_cValue = static_cast<char>(this->_dValue);
		this->_iValue = static_cast<int>(this->_dValue);
		this->_fValue = static_cast<float>(this->_dValue);
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
	char cValue = instance.getCValue();

	if (cValue == -1)
		out << "char\t: impossible\n";
	else if (cValue == -2)
		out << "char\t: Non displayable\n";
	else
		out << "char\t: '" << instance.getCValue() << "'\n";
	out << "int\t: " << instance.getIValue() << "\n";
	out << "float\t: " << instance.getFValue() << "f\n";
	out << "double\t: " << instance.getDValue() << "\n";
	return out;
}

// ************************** Libft functions ****************************** //
bool Convert::ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return true;
	return false;
}

bool Convert::ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return true;
	return false;
}
