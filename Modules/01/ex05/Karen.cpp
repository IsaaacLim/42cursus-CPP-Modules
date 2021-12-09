#include "Karen.hpp"

Karen::Karen(void)
{
	complains[0].level = "DEBUG";
	complains[0].func_ptr = &Karen::_debug;
	complains[1].level = "INFO";
	complains[1].func_ptr = &Karen::_info;
	complains[2].level = "WARNING";
	complains[2].func_ptr = &Karen::_warning;
	complains[3].level = "ERROR";
	complains[3].func_ptr = &Karen::_error;
	return;
}

Karen::~Karen(void) { return; }

void Karen::_debug(void)
{
	std::cout << "DEBUG\t: I love to get extra bacon for my";
	std::cout << " 7XL-double-cheese-tiple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
	return;
}

void Karen::_info(void)
{
	std::cout << "INFO\t: I cannot believe adding extrta bacon cost more money.";
	std::cout << " You don't put enough!";
	std::cout << " If you did I would not have to ask for it!" << std::endl;
	return;
}

void Karen::_warning(void)
{
	std::cout << "WARNING\t: I think I deserve to ahve some extra bacon for free.";
	std::cout << " I've bee coming here for years and";
	std::cout << " you just started working here last month" << std::endl;
	return;
}

void Karen::_error(void)
{
	std::cout << "ERROR\t: This is unacceptable,";
	std::cout << " I want to speak to the manager now." << std::endl;
	return;
}

void Karen::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (complains[i].level == level)
			return (this->*complains[i].func_ptr)();
	}
}
