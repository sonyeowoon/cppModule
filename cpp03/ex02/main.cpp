#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ScavTrap	scav("GateKeeper");
	FragTrap	frag("Fraggy");

	std::cout << "---- ScavTrap ----\n";
	scav.printStatus();
	scav.guardGate();
	scav.attack("target");

	std::cout << "\n---- FragTrap ----\n";
	frag.printStatus();
	frag.highFivesGuys();
	frag.attack("target");

	std::cout << "\n---- Copy ----\n";
	FragTrap	frag2(frag);
	FragTrap	frag3;
	frag3 = frag;

	frag2.attack("copy target");
	frag3.attack("assigned target");

	return 0;
}
