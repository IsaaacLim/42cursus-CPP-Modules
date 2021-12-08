#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
** From: https://youtu.be/KUx9YfHkllk
*/
int main(void)
{
	string rawData = "";
	string firstname = "";
	int age = 0;
	string occupation = "";

	istringstream issData;

	cout << "Enter: Firstname age occupation" << endl;
	getline(cin, rawData);
	cout << "Entered: " << rawData << endl;

	issData.str(rawData); //.str() is used to access the sequence of string characters
	issData >> firstname;
	issData >> age;
	issData >> occupation;

	cout << firstname << " is a " << age << " year old " << occupation << endl;
}
