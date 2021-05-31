#include "Zobie.hpp"

Zombie::Zombie()
{
	this->name = "defaultName";
	this->type = "defaultType";
}

Zombie::Zombie(std::string type, std::string name)
{
	this->name = type;
	this->type = name;
}

void Zombie::announce(void)
{
	std::cout << "<" << name << " (" << this->type << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}