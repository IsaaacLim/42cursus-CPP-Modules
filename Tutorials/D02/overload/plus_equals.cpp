#include <iostream>

/*
** From: https://youtu.be/ZcmQ5y7QyTc
*/
class Position
{
public:
	int x;
	int y;

	Position operator+(Position pos);
	bool operator==(Position pos);
};

/*
** Addition operator Overload
** Returning a new Position instance
** pos1 is going to call "operator+"
** pos2 is going to be passed as an arg
*/
Position Position::operator+(Position pos)
{
	Position new_pos;	   //define a new position
	new_pos.x = x + pos.x; //'x' is from pos1, 'pos.x' is from pos2
	new_pos.y = y + pos.y;
	return (new_pos);
}

/*
** Comparison operator overload
** Returning a boolean
*/
bool Position::operator==(Position pos)
{
	if (x == pos.x && y == pos.y)
		return true;
	return false;
}
int main()
{
	Position pos1, pos2;

	pos1.x = 8;
	pos1.y = 10;
	pos2.x = 8;
	pos2.y = 10;

	Position pos3 = pos1 + pos2;
	std::cout << "Pos3: " << pos3.x << " " << pos3.y << std::endl;

	if (pos1 == pos2)
		std::cout << "They are the same" << std::endl;
	else
		std::cout << "They are not the same" << std::endl;

	pos2.x = 12;
	if (pos1 == pos2)
		std::cout << "They are the same" << std::endl;
	else
		std::cout << "They are not the same" << std::endl;

	return 0;
}
