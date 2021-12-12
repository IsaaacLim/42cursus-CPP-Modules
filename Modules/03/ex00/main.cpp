#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ali("Ali");

	ali.attack("Ah Beng");
	ali.takeDamage(5);
	ali.beRepaired(2);

	ClapTrap ali2(ali);
	ali2.setName("Ali2");
	ali2.takeDamage(3);

	std::cout << "HitPoints remaining: Ali(" << ali.getHitPoints() << ") Ali2(";
	std::cout << ali2.getHitPoints() << ")" << std::endl;
	return 0;
}
