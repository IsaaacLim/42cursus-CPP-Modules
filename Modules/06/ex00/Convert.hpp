#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits>  //std::numeric_limits<T>
#include <climits> //INT_MAX/MIN
#include <float.h> //FLT_MAX/MIN
#include <cmath>

class Convert
{
private:
	Convert();

	//Functions
	void evaluateInput(void);
	void cast(void);
	// void cast_char(void);
	// void cast_int(void);
	// void cast_float(void);
	// void cast_double(void);

	//Variables
	std::string _input;
	int _type;

	enum e_type
	{
		eChar,
		eInt,
		eFloat,
		eDouble
	};

	//Values in correct type
	char _cValue;
	int _iValue;
	float _fValue;
	double _dValue;

	bool _isIntOverFlow = false;

public:
	Convert(std::string const &literal);
	~Convert();

	int getType(void) const;
	char getCValue(void) const;
	int getIValue(void) const;
	float getFValue(void) const;
	double getDValue(void) const;
	bool getIsIntOverFlow(void) const;

	//Libft functions
	static bool ft_isascii(int c);
	static bool ft_isdigit(int c);
	static bool ft_isprint(int c);
	static char *ft_strchr(const char *s, int c);
};

std::ostream &operator<<(std::ostream &out, Convert const &instance);

#endif
