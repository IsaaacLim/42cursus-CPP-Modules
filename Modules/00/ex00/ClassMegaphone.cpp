#include <iostream>
#include "ClassMegaphone.hpp"

Megaphone::Megaphone(void)
{
	return;
}

Megaphone::~Megaphone(void)
{
	return;
}

void Megaphone::ft_toupper(char *str[]) const
{
	for (int i = 1; str[i]; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			if (str[i][j] >= 'a' && str[i][j] <= 'z')
				std::cout << (char)(str[i][j] - ' ');
			else
				std::cout << str[i][j];
		}
	}
	std::cout << std::endl;
	return;
}
