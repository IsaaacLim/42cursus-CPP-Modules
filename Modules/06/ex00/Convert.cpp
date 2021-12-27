#include "Convert.hpp"

Convert::Convert(std::string const &literal) : _input(literal)
{
	this->evaluateInput();
	this->cast();
	if (!Convert::ft_isascii(_iValue))
		_cValue = -1;
	else if (!Convert::ft_isprint(_iValue))
		_cValue = -2;
}

Convert::~Convert() {}

void Convert::evaluateInput(void)
{
	std::stringstream ss;
	long long_int;
	long double long_double;
	int i;

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
		// std::cout << "Input\t: " << _input << "\n";
		_type = eFloat;
		_fValue = atof(_input.c_str());
		// std::cout << "Stored (flt)\t: " << _fValue << "\n";
	}
	//Double special case
	else if (_input == "nan" || _input == "inf" || _input == "+inf" || _input == "-inf")
	{
		// std::cout << "Input\t: " << _input << "\n";
		_type = eDouble;
		_dValue = strtod(_input.c_str(), NULL); //alt function
												// std::cout << "Stored (dbl)\t: " << _dValue << "\n";
	}
	//Other numbers
	else
	{
		_type = eInt;
		i = 0;
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
			// std::cout << "i = " << i << "input_len = " << input_len << "\n";
			_type = -1;
		}
		switch (_type)
		{
		case eInt:
			ss >> long_int;
			_iValue = static_cast<int>(long_int);
			if (long_int < _iValue || long_int > _iValue)
				_isIntOverFlow = true;
			break;
		case eFloat:
			ss >> long_double;
			_fValue = static_cast<float>(long_double); //turns to inf if over limits
			break;
		case eDouble:
			ss >> long_double;
			_dValue = static_cast<double>(long_double); //turns to inf if over limits
			break;
		default:
			break;
		}
	}
}

void Convert::cast(void)
{
	switch (_type)
	{
	case eChar:
	{
		// std::cout << "Type is char\n";
		_iValue = static_cast<int>(_cValue);
		_fValue = static_cast<float>(_cValue);
		_dValue = static_cast<double>(_cValue);
		break;
	}
	case eInt:
	{
		// std::cout << "Type is int\n";
		if (_iValue < 0)
			_cValue = -1;
		else
			_cValue = static_cast<char>(_iValue);
		_fValue = static_cast<float>(_iValue);
		_dValue = static_cast<double>(_iValue);
		break;
	}
	case eFloat:
	{
		// std::cout << "Type is float\n";
		_cValue = static_cast<char>(_fValue);
		_iValue = static_cast<int>(_fValue);
		if (std::isnan(_fValue))
			_isIntOverFlow = true;
		_dValue = static_cast<double>(_fValue);
		break;
	}
	case eDouble:
	{
		// std::cout << "Type is double\n";
		_cValue = static_cast<char>(_dValue);
		_iValue = static_cast<int>(_dValue);
		if (std::isnan(_dValue))
			_isIntOverFlow = true;
		_fValue = static_cast<float>(_dValue);
		break;
	}
	default:
	{
		std::cerr << "Something wrong with cast()\n";
		break;
	}
	}
}

int Convert::getType(void) const { return this->_type; }

char Convert::getCValue(void) const { return this->_cValue; }

int Convert::getIValue(void) const { return this->_iValue; }

float Convert::getFValue(void) const { return this->_fValue; }

double Convert::getDValue(void) const { return this->_dValue; }

bool Convert::getIsIntOverFlow(void) const { return this->_isIntOverFlow; }

std::ostream &operator<<(std::ostream &out, Convert const &instance)
{
	char cValue = instance.getCValue();
	float fValue = instance.getFValue();
	double dValue = instance.getDValue();
	std::stringstream tmp_ss;
	std::string tmp_str;
	bool has_decimal = false;
	//  num = static_cast<long>(instance.getFValue());
	// std::cout << "dValue: " << dValue << "\n";
	//Display wrong input
	if (instance.getType() == -1)
	{
		out << "char\t: unacceptable input\n";
		out << "int\t: unacceptable input\n";
		out << "float\t: unacceptable input\n";
		out << "double\t: unacceptable input\n";
		return out;
	}
	//Display Char
	if (cValue == -1 || instance.getIsIntOverFlow())
		out << "char\t: impossible\n";
	else if (cValue == -2)
		out << "char\t: Non displayable\n";
	else
		out << "char\t: '" << cValue << "'\n";
	//Display Int
	if (instance.getIsIntOverFlow() || fValue < INT_MIN || fValue > INT_MAX)
		out << "int\t: impossible\n";
	else
		out << "int\t: " << instance.getIValue() << "\n";
	//Display Float
	tmp_ss << fValue;
	tmp_ss >> tmp_str;
	if (Convert::ft_strchr(tmp_str.c_str(), '.'))
		has_decimal = true;
	if (tmp_str[0] == '-')
		tmp_str.erase(0, 1);
	if (has_decimal || (!Convert::ft_isdigit(tmp_str[0])))
		out << "float\t: " << fValue << "f\n";
	else
		out << "float\t: " << fValue << ".0f\n";
	tmp_ss.str(std::string());
	tmp_ss.clear();
	//Display Double
	tmp_ss << dValue;
	tmp_ss >> tmp_str;
	if (Convert::ft_strchr(tmp_str.c_str(), '.'))
		has_decimal = true;
	if (tmp_str[0] == '-')
		tmp_str.erase(0, 1);
	if (has_decimal || (!Convert::ft_isdigit(tmp_str[0])))
		out << "double\t: " << dValue << "\n";
	else
		out << "double\t: " << dValue << ".0\n";
	return out;
}

// ************************** Libft functions ****************************** //
bool Convert::ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return true;
	return false;
}

bool Convert::ft_isdigit(int c)
{
	bool isDigit;

	isDigit = ((c >= '0' && c <= '9') ? true : false);
	return isDigit;
}
bool Convert::ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

char *Convert::ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
