#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct_p1("CT_PLAYER1");

	ct_p1.attack("ENEMY1");
	ct_p1.takeDamage(5);
	ct_p1.beRepaired(2);

	ClapTrap ct_p2(ct_p1);
	ct_p2.setName("CT_PLAYER2");
	ct_p2.takeDamage(3);

	std::cout << "HitPoints remaining: CT_PLAYER1(" << ct_p1.getHitPoints() << ") CT_PLAYER2(";
	std::cout << ct_p2.getHitPoints() << ")" << std::endl;

	std::cout << "---- ScavTrap ----" << std::endl;
	ScavTrap st_p1("ST_PLAYER1");
	st_p1.attack("ENEMY1");
	st_p1.takeDamage(6);
	st_p1.beRepaired(4);

	ScavTrap st_p2(st_p1);
	st_p2.setName("ST_PLAYER2");
	st_p2.takeDamage(10);
	st_p2.guardGate();

	std::cout << "HitPoints remaining: CT_PLAYER1(" << ct_p1.getHitPoints() << ") CT_PLAYER2(";
	std::cout << ct_p2.getHitPoints() << ") ST_PLAYER1(" << st_p1.getHitPoints() << ") ST_PLAYER2(";
	std::cout << st_p2.getHitPoints() << ")" << std::endl;

	return 0;
}
