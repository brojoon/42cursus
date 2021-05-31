#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA human("john", club);
	human.attack();
	club.setType("some other type of club");
	human.attack();

	weapon club = Weapon("crude spiked club");
	HumanB jim("jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	return (0);
}