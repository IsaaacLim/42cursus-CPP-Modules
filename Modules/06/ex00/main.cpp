#include "Convert.hpp"
#include <limits>  //std::numeric_limits<T>
#include <float.h> //FLT_MAX/MIN
#include <climits> //CHAR_MAX/MIN
#include <cmath>   //nan

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

	float test = 123e10f;
	std::cout << "\n Test\t: " << test << "\n";
	std::cout << "\n";
	// ********************************************************************** //
	std::cout << " nan\t:  " << nan("") << "\n";
	std::cout << "+nan\t:  " << +nan("") << "\n";
	std::cout << "-nan\t: " << -nan("") << "\n";
	std::cout << " nanf\t:  " << nanf("") << "\n";
	std::cout << "+nanf\t:  " << +nanf("") << "\n";
	std::cout << "-nanf\t: " << -nanf("") << "\n";
}

int main(int argc, char *argv[])
{
	ft_display_edges();
	// return (0);
	if (argc != 2)
		std::cout << "Input ONE argument to be converted" << std::endl;
	else
	{
		Convert instance(argv[1]);
		std::cout << instance << std::endl;
	}

	for (int i = -20; i < 150; i++)
	{
		if (!isascii(i))
			printf("%d, ", i);
	}
}
