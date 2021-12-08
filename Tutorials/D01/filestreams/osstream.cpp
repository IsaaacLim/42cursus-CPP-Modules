#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

/*
** From: https://youtu.be/4zCqtUVAReY
** Using osstream allows us to edit our string before writting it to output
*/
int main()
{
	ostringstream oss;
	string myvar = "\nThis line came first.";

	oss << "This line came after." << myvar << endl;
	oss << setw(30) << "Format" << endl;
	oss << setw(30) << left << "Format: Left" << endl;
	oss << fixed << setprecision(6) << 567.1234546789 << endl;
	oss.write("\nused write", 11);

	cout << oss.str(); ///str() to access the sequence of string character
	cout << "\nEnd of file" << endl;
}
