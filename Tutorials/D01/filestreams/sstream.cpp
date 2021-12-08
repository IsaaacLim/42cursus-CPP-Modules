#include <iostream>
#include <sstream>

using namespace std;

/*
** From: https://youtu.be/LM6EDIKS5Pk
*/
void ft_str2int(void)
{
	int input;
	stringstream sso;
	string number = "44";

	sso << number;
	sso >> input;

	cout << "Int: " << input + 2 << endl;
	cout << "Str: " << number + "2" << endl;
}

void ft_int2str(void)
{
	int input;
	stringstream sso;
	string strinput;

	cout << "Enter integer: " << endl;
	cin >> input;
	sso << input;
	sso >> strinput;

	cout << "Entered(int): " << input << endl;
	cout << "Entered(str): " << strinput << endl;
}

int main()
{
	// ft_int2str();
	ft_str2int();
}
