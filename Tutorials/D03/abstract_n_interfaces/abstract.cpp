#include <iostream>

using namespace std;

/*
** Virtual: Since the function is virtual, it goes back down to see what the Enemy
**	class variable is pointing to.
**
** Pure virtual function: is a parent function that doesn't provide the option
**	for the child to inherit it. It has no implementation (body). It doesn't do anything
**	Classes derived from class with PVF MUST override that function.
**
** Abstract class: A class with only pure virtual functions in it.
*/
class Enemy
{
public:
	virtual void attack() { cout << "I am the enemy class attack" << endl; }
	virtual void defense() { cout << "I am the enemy class defense" << endl; }
	// virtual void run() = 0; //enemy3 will complain
};

class Ninja : public Enemy
{
public:
	void attack() { cout << "ninja attack!" << endl; }
	void defense() { cout << "ninja defense!" << endl; }
	void run() { cout << "ninja run!" << endl; }
};

class Monster : public Enemy
{
public:
	void attack() { cout << "monster attack!" << endl; }
	void run() { cout << "monster run!" << endl; }
};

int main(void)
{
	Ninja n;
	Monster m;
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	Enemy enemy3 = Ninja(); //will complain with PVF

	enemy1->attack();
	enemy2->attack();
	enemy3.attack(); //virtual doesn't work here

	enemy1->defense();
	enemy2->defense(); //no overriding function
	enemy3.defense();  //virtual doesn't work here
}
