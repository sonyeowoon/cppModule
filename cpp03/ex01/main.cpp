#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	base("Base");
	ScavTrap	scav("Serena");

	base.printStatus();
	scav.printStatus();

	std::cout << "---- Base attacks ----\n";
	base.attack("enemy");
	base.takeDamage(5);
	base.beRepaired(3);

	std::cout << "\n---- ScavTrap attacks ----\n";
	scav.attack("target");
	scav.guardGate();

	std::cout << "\n---- Copy / assignment test ----\n";
	ScavTrap copy(scav);
	ScavTrap assigned;
	assigned = scav;

	copy.attack("copy target");
	assigned.attack("assigned target");

	return 0;
}
