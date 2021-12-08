#ifndef CLASSREPLACE_HPP
#define CLASSREPLACE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Replace
{
public:
	Replace(void);
	~Replace(void);

	static void ft_replace(std::string filein, std::string str1, std::string str2);
};

#endif
