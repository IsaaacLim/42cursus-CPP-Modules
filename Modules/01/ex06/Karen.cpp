#include "Karen.hpp"

Karen::Karen(void) { return; }

Karen::~Karen(void) { return; }

void Karen::_debug(void)
{
	std::cout << "[DEBUG]\nI love to get extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << "\nI just love it!\n";
	return;
}

void Karen::_info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon cost more money.";
	std::cout << "\nYou don't put enough!";
	std::cout << "\nIf you did I would not have to ask for it!\n";
	return;
}

void Karen::_warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.";
	std::cout << "\nI've been coming here for years and";
	std::cout << " you just started working here last month\n";
	return;
}

void Karen::_error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable,";
	std::cout << " I want to speak to the manager now.\n";
	return;
}

void Karen::complain(std::string level)
{
	std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levels = 4;

	for (int i = 0; i < 4; i++)
	{
		if (complains[i] == level)
			levels = i;
	}
	switch (levels)
	{
	case Debug:
		this->_debug();
		std::cout << std::endl;
	case Info:
		this->_info();
		std::cout << std::endl;
	case Warning:
		this->_warning();
		std::cout << std::endl;
	case Error:
		this->_error();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complainig about insignificant problems ]" << std::endl;
	}
}
