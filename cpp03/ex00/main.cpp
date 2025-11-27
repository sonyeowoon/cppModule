#include "ClapTrap.hpp"

int	main() {
	ClapTrap	unknown;
	ClapTrap	a("A");
	ClapTrap	b("B");

	unknown.printStatus();
	a.printStatus();
	b.printStatus();
	ClapTrap	tmp(b);
	tmp.printStatus();
	tmp = a;
	tmp.printStatus();

	a.attack("B");
	b.takeDamage(0);

	a.beRepaired(5);
	a.attack("some target");
	a.takeDamage(15);

	a.attack("another target");
	a.beRepaired(10);
	tmp.printStatus();

	return 0;
}
