#include <limits>  //std::numeric_limits<T>
#include <float.h> //FLT_MAX/MIN
#include <climits> //CHAR_MAX/MIN
#include <cmath>   //nan
#include <string.h>
#include "Convert.hpp"

/*
** Has 2 main syntax to obtain the limits
**	https://en.cppreference.com/w/cpp/types/numeric_limits/min
*/
void ft_display_edges(void)
{
	double neg_inf = -std::numeric_limits<double>::infinity();
	double neg_dbl_max = -DBL_MAX;
	float neg_inff = -std::numeric_limits<float>::infinity();
	float neg_flt_max = -FLT_MAX;
	int int_min = INT_MIN;
	int char_min = CHAR_MIN;
	float neg_flt_min = -FLT_MIN;
	double neg_dbl_min = -std::numeric_limits<double>::min();
	int zero = 0;
	double dbl_min = DBL_MIN;
	float flt_min = FLT_MIN;
	int char_max = CHAR_MAX;
	int int_max = std::numeric_limits<int>::max();
	float flt_max = FLT_MAX;
	float inff = std::numeric_limits<float>::infinity();
	double dbl_max = DBL_MAX;
	double inf = std::numeric_limits<double>::infinity();

	std::cout << "-inff (double)\t: " << neg_inf << "\n";
	std::cout << "-Dbl max\t: " << neg_dbl_max << "\n";
	std::cout << "-inff (flt)\t: " << neg_inff << "\n";
	std::cout << "-Flt max\t: " << neg_flt_max << "\n";
	std::cout << " Int min\t: " << int_min << "\n";
	std::cout << " Char min\t: " << char_min << "\n";
	std::cout << "-Flt min\t: " << neg_flt_min << "\n";
	std::cout << "-Dbl min\t: " << neg_dbl_min << "\n";
	std::cout << " ZERO\t\t:  " << zero << "\n";
	std::cout << " Dbl min\t:  " << dbl_min << "\n";
	std::cout << " Flt min\t:  " << flt_min << "\n";
	std::cout << " Char max\t:  " << char_max << "\n";
	std::cout << " Int max\t:  " << int_max << "\n";
	std::cout << " Flt max\t:  " << flt_max << "\n";
	std::cout << " inff (flt)\t:  " << inff << "\n";
	std::cout << " Dbl max\t:  " << dbl_max << "\n";
	std::cout << " inf (dbl)\t:  " << inf << "\n";

	// float test = 123e10f;
	// std::cout << "\n Test\t: " << test << "\n";
	// std::cout << "\n";
	// ********************************************************************** //
	std::cout << " nan\t:  " << nan("") << "\n";
	std::cout << "+nan\t:  " << +nan("") << "\n";
	std::cout << "-nan\t: " << -nan("") << "\n";
	std::cout << " nanf\t:  " << nanf("") << "\n";
	std::cout << "+nanf\t:  " << +nanf("") << "\n";
	std::cout << "-nanf\t: " << -nanf("") << "\n\n";
}

void ft_test_instance(std::string test, long double num)
{
	std::stringstream ss;
	std::string str;

	std::cout << "--- " << test << " ---\n";
	ss << num;
	ss >> str;
	Convert instance(str.c_str());
	std::cout << instance << std::endl;
	// ss.str(std::string()); //needed if reusing strinstream in same function
	// ss.clear();
}

void ft_test_instance_int(std::string test, long num)
{
	std::stringstream ss;
	std::string str;

	std::cout << "--- " << test << " ---\n";
	ss << num;
	ss >> str;
	Convert instance(str.c_str());
	std::cout << instance << std::endl;
	// ss.str(std::string()); //needed if reusing strinstream in same function
	// ss.clear();
}

void ft_test_double()
{
	std::cout << "====== DOUBLE TESTS ======\n";
	ft_test_instance("-DBL MAX", -DBL_MAX);
	ft_test_instance("-DBL MIN", -DBL_MIN);
	ft_test_instance("DBL MIN", DBL_MIN);
	ft_test_instance("DBL MAX", DBL_MAX);
	ft_test_instance("-DBL MAX - 1e303", -DBL_MAX - 1e303);
	ft_test_instance("DBL MAX + 1e303", DBL_MAX + 1e303);
}

void ft_test_float()
{
	std::cout << "====== FLOAT TESTS ======\n";
	ft_test_instance("-FLT MAX", -FLT_MAX);
	ft_test_instance("-FLT MIN", -FLT_MIN);
	ft_test_instance("FLT MIN", FLT_MIN);
	ft_test_instance("FLT MAX", FLT_MAX);
	ft_test_instance("-FLT MAX - 1e33", -FLT_MAX - 1e33);
	ft_test_instance("FLT MAX + 1e33", FLT_MAX + 1e33);
}

void ft_test_int()
{
	std::cout << "====== INT TESTS ======\n";
	ft_test_instance_int("INT MIN", INT_MIN);
	ft_test_instance_int("INT MAX", INT_MAX);
	ft_test_instance_int("INT MIN - 1", -2147483649);
	ft_test_instance_int("INT MAX + 1", 2147483648);
}

int main(int argc, char *argv[])
{
	ft_display_edges();
	if (argc == 2)
	{
		if (!strcmp(argv[1], "double"))
			ft_test_double();
		else if (!strcmp(argv[1], "float"))
			ft_test_float();
		else if (!strcmp(argv[1], "int"))
			ft_test_int();
	}
}
